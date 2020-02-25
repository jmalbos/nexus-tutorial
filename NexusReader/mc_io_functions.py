import os
import sys
import tables as tb
import pandas as pd

import invisible_cities.core.system_of_units  as units


def load_mc_hits_oldFormat(iFileName: str) -> pd.DataFrame :

    # Loading data
    extents   = pd.read_hdf(iFileName, 'MC/extents')

    with tb.open_file(iFileName ,mode='r') as iFile:
        hits_tb  = iFile.root.MC.hits
    
        # Generating hits DataFrame
        hits = pd.DataFrame({'hit_id'      : hits_tb.col('hit_indx'),
                             'particle_id' : hits_tb.col('particle_indx'),
                             'label'       : hits_tb.col('label').astype('U13'),
                             'time'        : hits_tb.col('hit_time'),
                             'x'           : hits_tb.col('hit_position')[:, 0],
                             'y'           : hits_tb.col('hit_position')[:, 1],
                             'z'           : hits_tb.col('hit_position')[:, 2],
                             'E'           : hits_tb.col('hit_energy')})
                
        evt_hit_df = extents[['last_hit', 'evt_number']]
        evt_hit_df.set_index('last_hit', inplace = True)
        hits = hits.merge(evt_hit_df, left_index=True, right_index=True, how='left')
        hits.rename(columns={"evt_number": "event_id"}, inplace = True)
        hits.event_id.fillna(method='bfill', inplace = True)
        hits.event_id = hits.event_id.astype(int)

        # Setting the indexes
        hits.set_index(['event_id', 'particle_id', 'hit_id'], inplace=True)
        
    return hits



def load_mc_hits(iFileName: str) -> pd.DataFrame :

    # If iFileName follows the old-format, use the oldFormat function
    try: 
        pd.read_hdf(iFileName, 'MC/extents')
        return load_mc_hits_oldFormat(iFileName)

    # If iFileName follows the new-format: read DF and set index
    except:
        hits = pd.read_hdf(iFileName, 'MC/hits')
        hits.set_index(['event_id', 'particle_id', 'hit_id'], inplace=True)
        return hits



def load_mc_particles_oldFormat(iFileName: str) -> pd.DataFrame :

    # Loading data
    extents   = pd.read_hdf(iFileName, 'MC/extents')

    with tb.open_file(iFileName ,mode='r') as iFile:
        parts_tb = iFile.root.MC.particles
    
        # Generating parts DataFrame
        parts = pd.DataFrame({'particle_id'    : parts_tb.col('particle_indx'),
                              'name'           : parts_tb.col('particle_name').astype('U20'),
                              'primary'        : parts_tb.col('primary').astype('bool'),
                              'mother_id'      : parts_tb.col('mother_indx'),
                              'ini_x'          : parts_tb.col('initial_vertex')[:, 0],
                              'ini_y'          : parts_tb.col('initial_vertex')[:, 1],
                              'ini_z'          : parts_tb.col('initial_vertex')[:, 2],
                              'ini_t'          : parts_tb.col('initial_vertex')[:, 3],
                              'final_x'        : parts_tb.col('final_vertex')[:, 0],
                              'final_y'        : parts_tb.col('final_vertex')[:, 1],
                              'final_z'        : parts_tb.col('final_vertex')[:, 2],
                              'final_t'        : parts_tb.col('final_vertex')[:, 3],
                              'initial_volume' : parts_tb.col('initial_volume').astype('U20'),
                              'final_volume'   : parts_tb.col('final_volume').astype('U20'),
                              'ini_px'         : parts_tb.col('momentum')[:, 0],
                              'ini_py'         : parts_tb.col('momentum')[:, 1],
                              'ini_pz'         : parts_tb.col('momentum')[:, 2],
                              'kin_energy'     : parts_tb.col('kin_energy'),
                              'creator_proc'   : parts_tb.col('creator_proc').astype('U20')})
                              
        # Adding event info
        evt_part_df = extents[['last_particle', 'evt_number']]
        evt_part_df.set_index('last_particle', inplace = True)
        parts = parts.merge(evt_part_df, left_index=True, right_index=True, how='left')
        parts.rename(columns={"evt_number": "event_id"}, inplace = True)
        parts.event_id.fillna(method='bfill', inplace = True)
        parts.event_id = parts.event_id.astype(int)

        # Setting the indexes
        parts.set_index(['event_id', 'particle_id'], inplace=True)

    return parts



def load_mc_particles(iFileName: str) -> pd.DataFrame :

    # If iFileName follows the old-format, use the oldFormat function
    try: 
        pd.read_hdf(iFileName, 'MC/extents')
        return load_mc_particles_oldFormat(iFileName)

    # If iFileName follows the new-format: read DF and set index
    except:
        parts = pd.read_hdf(iFileName, 'MC/particles')
        parts.set_index(['event_id', 'particle_id'], inplace=True)
        return parts



def load_mc_sensor_response_oldFormat(iFileName: str) -> pd.DataFrame :

    # Loading data
    extents      = pd.read_hdf(iFileName, 'MC/extents')
    sns_response = pd.read_hdf(iFileName, 'MC/waveforms')

    evt_sns  = extents[['last_sns_data', 'evt_number']]
    evt_sns.set_index('last_sns_data', inplace = True)

    sns_response = sns_response.merge(evt_sns             ,
                                      left_index  =   True,
                                      right_index =   True,
                                      how         = 'left')
    sns_response.evt_number.fillna(method='bfill', inplace = True)


    sns_response.evt_number = sns_response.evt_number.astype(int)
    sns_response.rename(columns = {'evt_number': 'event_id'}, inplace = True)
    sns_response.set_index(['event_id', 'sensor_id'], inplace = True)

    return sns_response



def load_mc_sensor_response(iFileName: str) -> pd.DataFrame :

    # If iFileName follows the old-format, use the oldFormat function
    try: 
        pd.read_hdf(iFileName, 'MC/extents')
        return load_mc_sensor_response_oldFormat(iFileName)

    # If iFileName follows the new-format, read DF and set index
    except:
        sns_response = pd.read_hdf(iFileName, 'MC/sns_response')
        sns_response.set_index(['event_id', 'sensor_id'], inplace=True)
        return sns_response



def get_num_mc_particles(extents: pd.DataFrame, event_number: int) -> int :
    # Getting the index of the event number
    idx = extents[extents['evt_number'] == event_number].index.item()

    # Calculating the number of particles
    if (idx == 0):
        num_parts = extents.iloc[idx].last_particle + 1
    else:
        num_parts = extents.iloc[idx].last_particle - extents.iloc[idx-1].last_particle
        
    return num_parts
