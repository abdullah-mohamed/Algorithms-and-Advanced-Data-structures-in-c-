##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RBT_xieping_github
ConfigurationName      :=Debug
WorkspacePath          :="E:/practical practice/codes/mostafa_saad_sheet/DataStructures"
ProjectPath            :="E:/practical practice/codes/mostafa_saad_sheet/DataStructures/RBT_xieping_github"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=abdullah
Date                   :=05/05/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RBT_xieping_github.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/ar.exe" rcu
CXX      := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
CC       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe"
CXXFLAGS := -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/RBT.cpp$(ObjectSuffix) $(IntermediateDirectory)/RBT.c$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/RBT.cpp$(ObjectSuffix): RBT.cpp $(IntermediateDirectory)/RBT.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/practical practice/codes/mostafa_saad_sheet/DataStructures/RBT_xieping_github/RBT.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RBT.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RBT.cpp$(DependSuffix): RBT.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RBT.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RBT.cpp$(DependSuffix) -MM RBT.cpp

$(IntermediateDirectory)/RBT.cpp$(PreprocessSuffix): RBT.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RBT.cpp$(PreprocessSuffix) RBT.cpp

$(IntermediateDirectory)/RBT.c$(ObjectSuffix): RBT.c $(IntermediateDirectory)/RBT.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/practical practice/codes/mostafa_saad_sheet/DataStructures/RBT_xieping_github/RBT.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RBT.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RBT.c$(DependSuffix): RBT.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RBT.c$(ObjectSuffix) -MF$(IntermediateDirectory)/RBT.c$(DependSuffix) -MM RBT.c

$(IntermediateDirectory)/RBT.c$(PreprocessSuffix): RBT.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RBT.c$(PreprocessSuffix) RBT.c

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/practical practice/codes/mostafa_saad_sheet/DataStructures/RBT_xieping_github/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


