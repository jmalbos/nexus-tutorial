// -----------------------------------------------------------------------------
//  G4Basic | PrimaryGeneration.cpp
//
//
// -----------------------------------------------------------------------------

#include "PrimaryGeneration.h"

#include <G4IonTable.hh>
#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>
#include <G4PrimaryParticle.hh>
#include <G4PrimaryVertex.hh>
#include <G4Event.hh>
#include <G4RandomDirection.hh>


PrimaryGeneration::PrimaryGeneration():
  G4VUserPrimaryGeneratorAction()
{
}


PrimaryGeneration::~PrimaryGeneration()
{
}


void PrimaryGeneration::GeneratePrimaries(G4Event* event)
{
  static G4ParticleDefinition* Kr83m =
    G4IonTable::GetIonTable()->GetIon(36, 83, 42.*keV);

  G4PrimaryParticle* particle = new G4PrimaryParticle(Kr83m);
  particle->SetMomentumDirection(G4RandomDirection());
  particle->SetKineticEnergy(0.);

  G4PrimaryVertex* vertex = new G4PrimaryVertex(RandomPosition(), 0.);
  vertex->SetPrimary(particle);

  event->AddPrimaryVertex(vertex);
}


G4ThreeVector PrimaryGeneration::RandomPosition() const
{
  const G4double min = -1.*m;
  const G4double max =  1.*m;

  G4double posx = min + max * 2. * G4UniformRand();
  G4double posy = min + max * 2. * G4UniformRand();
  G4double posz = min + max * 2. * G4UniformRand();

  return G4ThreeVector(posx,posy,posz);
}
