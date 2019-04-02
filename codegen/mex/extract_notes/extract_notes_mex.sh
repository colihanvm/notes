MATLAB="/Applications/MATLAB_R2015a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/vanessacolihan/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for extract_notes" > extract_notes_mex.mki
echo "CC=$CC" >> extract_notes_mex.mki
echo "CFLAGS=$CFLAGS" >> extract_notes_mex.mki
echo "CLIBS=$CLIBS" >> extract_notes_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> extract_notes_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> extract_notes_mex.mki
echo "CXX=$CXX" >> extract_notes_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> extract_notes_mex.mki
echo "CXXLIBS=$CXXLIBS" >> extract_notes_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> extract_notes_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> extract_notes_mex.mki
echo "LD=$LD" >> extract_notes_mex.mki
echo "LDFLAGS=$LDFLAGS" >> extract_notes_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> extract_notes_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> extract_notes_mex.mki
echo "Arch=$Arch" >> extract_notes_mex.mki
echo OMPFLAGS= >> extract_notes_mex.mki
echo OMPLINKFLAGS= >> extract_notes_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> extract_notes_mex.mki
echo "EMC_CONFIG=optim" >> extract_notes_mex.mki
"/Applications/MATLAB_R2015a.app/bin/maci64/gmake" -B -f extract_notes_mex.mk
