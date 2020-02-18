// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.cpp
//
//
// -----------------------------------------------------------------------------

#include "DetectorConstruction.h"

#include <G4Box.hh>
#include <G4Tubs.hh>
#include <G4Sphere.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>
#include <G4PhysicalConstants.hh>
#include <G4NistManager.hh>
#include <G4VisAttributes.hh>
#include <G4RotationMatrix.hh>


DetectorConstruction::DetectorConstruction(): G4VUserDetectorConstruction()
{
}


DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // WORLD /////////////////////////////////////////////////

  G4String world_name = "WORLD";
  G4double world_size = 25.*m;

  G4Sphere* world_solid_vol =
    new G4Sphere(world_name, 0., world_size/2., 0., 360.*deg, 0., 180.*deg);

  G4LogicalVolume* world_logic_vol =
    new G4LogicalVolume(world_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_Galactic"),
                        world_name);

  G4VPhysicalVolume* world_phys_vol =
    new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.),
                      world_logic_vol, world_name, nullptr,
                      false, 0, true);

  world_logic_vol->SetVisAttributes(G4VisAttributes::Invisible);

  // SHIELDING /////////////////////////////////////////////

  G4String shield_name   = "SHIELDING";
  G4double shield_diam   = 10.*m;
  G4double shield_height = 10.*m;

  G4Tubs* shield_solid_vol =
    new G4Tubs(shield_name, 0., shield_diam/2., shield_height/2., 0., 360*deg);

  G4LogicalVolume* shield_logic_vol =
    new G4LogicalVolume(shield_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        shield_name);

  G4RotationMatrix* rotX = new G4RotationMatrix();
  rotX->rotateX(90*deg);

  new G4PVPlacement(rotX, G4ThreeVector(0.,0.,0.),
                    shield_logic_vol, shield_name, world_logic_vol,
                    false, 0, true);

  // DETECTOR //////////////////////////////////////////////

  G4String detector_name = "DETECTOR";
  G4double detector_size = 2.*m;

  G4Box* detector_solid_vol =
    new G4Box(detector_name, detector_size/2., detector_size/2., detector_size/2.);

  G4LogicalVolume* detector_logic_vol =
    new G4LogicalVolume(detector_solid_vol, EnrichedXenon(), detector_name);

  new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),
                    detector_logic_vol, detector_name, shield_logic_vol,
                    false, 0, true);

  //////////////////////////////////////////////////////////

  return world_phys_vol;
}


G4Material* DetectorConstruction::EnrichedXenon() const
{
  G4String name = "ENRICHED_XENON";
  G4double pressure    = 15.0 * bar;
  G4double temperature = STP_Temperature; // 273.15 K
  G4double density     = 97.49 * kg/m3;

  G4Material* material =
    new G4Material(name, density, 1, kStateGas, temperature, pressure);

  G4Element* Xe = new G4Element("ENRICHED_XENON", "Xe", 2);

  G4Isotope* Xe134 = new G4Isotope("Xe134", 54, 134, 133.905395*g/mole);
  G4Isotope* Xe136 = new G4Isotope("Xe136", 54, 136, 135.907219*g/mole);
  Xe->AddIsotope(Xe134,  9.*perCent);
  Xe->AddIsotope(Xe136, 91.*perCent);

  material->AddElement(Xe,1);

  return material;
}
