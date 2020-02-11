// G4Basic | PrimaryGeneration.h

#ifndef PRIMARY_GENERATION_H
#define PRIMARY_GENERATION_H

#include <G4VUserPrimaryGeneratorAction.hh>

class G4ParticleDefinition;


class PrimaryGeneration: public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneration();
  virtual ~PrimaryGeneration();
  virtual void GeneratePrimaries(G4Event*);
};

#endif
