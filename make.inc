MAKE = make
F90 = mpiifort
CXX = mpiicxx
CC = mpiicc
CPP_OPTS = -D_MPI_

F90_OPTS = -g -cpp $(CPP_OPTS)
#F90_OPTS = -O0 -Wall -g -cpp -fbounds-check -fdump-core -fbacktrace $(CPP_OPTS)
F90_LINK_OPTS=$(F90_OPTS)

LAPACK_LIB = -mkl 

# === compile with HDF5 support ===
CPP_OPTS := $(CPP_OPTS) -D_HDF5_ $(HDF5_INC)
HDF5_LIB_FLAGS = $(HDF5_LIB) -lhdf5_fortran -lhdf5_cpp -lhdf5_hl -lhdf5

# ==- compile with libXC support ===
#CPP_OPTS := $(CPP_OPTS) -D_LIBXC_
XC_LIB =

# ==- compile with NFFT support ===
#CPP_OPTS := $(CPP_OPTS) -D_NFFT_
#NFFT_INC = -I$(HOME)/local/include
#NFFT_LIB = $(HOME)/local/lib/libnfft3.a $(HOME)/local/lib/libfftw3.a

# === compile with Madness API ===
#CPP_OPTS := $(CPP_OPTS) -D_MAD_
#MADNESS_INC = -I$(HOME)/local/include
#MADNESS_LIB = -L$(HOME)/local/lib/ -lMADmra -lMADlinalg -lMADtensor -lMADmisc -lMADmuparser -lMADtinyxml -lMADworld -lmpichcxx -lstdc++

# === collect all libraries under one name ===
LIBS = $(LAPACK_LIB) $(HDF5_LIB_FLAGS) $(XC_LIB) $(NFFT_LIB) $(MADNESS_LIB)

