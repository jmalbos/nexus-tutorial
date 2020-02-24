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
  // FACE //////////////////////////////////////////////////

  G4String face_name   = "FACE";
  G4double face_diam   = 700.*cm;
  G4double face_thickn = 100.*cm;

  G4Tubs* face_solid_vol =
    new G4Tubs(face_name, 0., face_diam/2., face_thickn/2., 0., 360.*deg);

  G4LogicalVolume* face_logic_vol =
    new G4LogicalVolume(face_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        face_name);

  G4PVPlacement* face_phys_vol =
    new G4PVPlacement(nullptr, G4ThreeVector(),
                      face_logic_vol, face_name, nullptr,
                      false, 0, true);

  // MOUTH /////////////////////////////////////////////////

  G4String mouth_name   = "MOUTH";
  G4double mouth_diam   = face_diam / 1.5;
  G4double mouth_thickn = face_thickn;

  G4Tubs* mouth_solid_vol =
    new G4Tubs(mouth_name, 0., mouth_diam/2., mouth_thickn/2., 0., 180.*deg);

  G4LogicalVolume* mouth_logic_vol =
    new G4LogicalVolume(mouth_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        mouth_name);

  G4RotationMatrix* rotZ = new G4RotationMatrix();
  rotZ->rotateZ(180.*deg);

  G4PVPlacement* mouth_phys_vol =
    new G4PVPlacement(rotZ, G4ThreeVector(0.,0.,0.),
                      mouth_logic_vol, mouth_name, face_logic_vol,
                      false, 0, true);

  // TONGUE ////////////////////////////////////////////////

  G4String tongue_name   = "TONGUE";
  G4double tongue_diam   = 3.*face_diam/8.;
  G4double tongue_thickn = face_thickn;

  G4Tubs* tongue_solid_vol =
    new G4Tubs(tongue_name, 0., tongue_diam/2., tongue_thickn/2., 0., 180.*deg);

  G4LogicalVolume* tongue_logic_vol =
    new G4LogicalVolume(tongue_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        tongue_name);

  G4double tongue_posy = tongue_diam/2. - (face_diam/2.)/7.;

  G4PVPlacement* tongue_phys_vol =
    new G4PVPlacement(nullptr, G4ThreeVector(0., tongue_posy, 0.),
                      tongue_logic_vol, tongue_name, mouth_logic_vol,
                      false, 0, true);

  // EYES //////////////////////////////////////////////////

  G4String eyes_name   = "EYES";
  G4double eyes_diam   = face_diam/7.;
  G4double eyes_thickn = face_thickn;

  G4Tubs* eyes_solid_vol =
    new G4Tubs(eyes_name, 0., eyes_diam/2., eyes_thickn/2., 0., 360.*deg);

  G4LogicalVolume* eyes_logic_vol =
    new G4LogicalVolume(eyes_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        eyes_name);

  G4double eyes_posx = (face_diam/4.) * std::cos(55.*deg);
  G4double eyes_posy = (face_diam/4.) * std::sin(55.*deg);

  new G4PVPlacement(nullptr, G4ThreeVector(eyes_posx, eyes_posy, 0.),
                    eyes_logic_vol, eyes_name, face_logic_vol,
                    false, 0, true);

  new G4PVPlacement(nullptr, G4ThreeVector(-eyes_posx, eyes_posy, 0.),
                    eyes_logic_vol, eyes_name, face_logic_vol,
                    false, 1, true);

  //////////////////////////////////////////////////////////

  return face_phys_vol;
}
