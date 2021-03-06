/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmGlobalVisualStudio10IA64Generator.h"
#include "cmMakefile.h"
#include "cmake.h"

//----------------------------------------------------------------------------
cmGlobalVisualStudio10IA64Generator::cmGlobalVisualStudio10IA64Generator()
{
}

//----------------------------------------------------------------------------
void cmGlobalVisualStudio10IA64Generator
::GetDocumentation(cmDocumentationEntry& entry) const
{
  entry.Name = this->GetName();
  entry.Brief = "Generates Visual Studio 10 Itanium project files.";
  entry.Full = "";
}

//----------------------------------------------------------------------------
void cmGlobalVisualStudio10IA64Generator
::AddPlatformDefinitions(cmMakefile* mf)
{
  this->cmGlobalVisualStudio10Generator::AddPlatformDefinitions(mf);
  mf->AddDefinition("CMAKE_FORCE_IA64", "TRUE");
  mf->AddDefinition("MSVC_C_ARCHITECTURE_ID", "x64");
  mf->AddDefinition("MSVC_CXX_ARCHITECTURE_ID", "x64");
}

//----------------------------------------------------------------------------
void cmGlobalVisualStudio10IA64Generator
::EnableLanguage(std::vector<std::string> const& languages,
                 cmMakefile* mf, bool optional)
{
  if(this->IsExpressEdition() && !this->Find64BitTools(mf))
    {
    return;
    }
  this->cmGlobalVisualStudio10Generator
    ::EnableLanguage(languages, mf, optional);
}
