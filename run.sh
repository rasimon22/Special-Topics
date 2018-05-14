!/bin/bash
#SBATCH -J ring
#SBATCH --ntasks=30
#SBATCH --partition=development
#SBATCH -o ring.out

module purge
module load gcc-6.3 openmpi
cd src
make
#mpirun -np ${SLURM_NTASKS} a.out
