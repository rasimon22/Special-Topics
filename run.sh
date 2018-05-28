#!/bin/bash
#SBATCH -J ring
#SBATCH --ntasks=30
#SBATCH --partition=development
#SBATCH -o ring.out

module purge
module load gcc-6.3 openmpi
#cd src
make
src/output
#mpirun -np ${SLURM_NTASKS} a.out
