# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL     = CameraCalImageCapture
TARGET      = sfun
MODULE_SRCS   = c2_CameraCalImageCapture.c half_type.c
MODEL_SRC  = CameraCalImageCapture_sfun.c
MODEL_REG = CameraCalImageCapture_sfun_registry.c
MAKEFILE    = CameraCalImageCapture_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2022b
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "E:\intro_robotics\finalproject\matlab april tag example\slprj\_sfprj\cameracalimagecapture\_self\sfun\src" /I "E:\intro_robotics\finalproject\matlab april tag example" /I "E:\intro_robotics\finalproject"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2022b\extern\include" \
    /I "C:\Program Files\MATLAB\R2022b\simulink\include" \
    /I "C:\Program Files\MATLAB\R2022b\simulink\include\sf_runtime" \
    /I "C:\Program Files\MATLAB\R2022b\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2022b\rtw\c\src" \
    /I "E:\Intro_Robotics\FinalProject\Matlab April Tag Example\slprj\_sfprj\CameraCalImageCapture\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\include" /I "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\export\include\vision"
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD  
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS)

USER_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS     = \
     "c_mexapi_version.obj" \
     "insertShapeUtilsCore.obj" \
     "cvstDraw.obj" \
     "insertShapeAndMarkerUtils.obj" \

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = CameraCalImageCapture_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(DSP_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


c_mexapi_version.obj :  "C:\Program Files\MATLAB\R2022b\extern\version\c_mexapi_version.c"
	@echo ### Compiling "C:\Program Files\MATLAB\R2022b\extern\version\c_mexapi_version.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\extern\version\c_mexapi_version.c"
insertShapeUtilsCore.obj :  "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeUtilsCore.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeUtilsCore.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeUtilsCore.cpp"
cvstDraw.obj :  "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\cvstDraw.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\cvstDraw.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\cvstDraw.cpp"
insertShapeAndMarkerUtils.obj :  "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeAndMarkerUtils.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeAndMarkerUtils.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\toolbox\vision\builtins\src\vision\insertShapeAndMarkerUtils.cpp"
