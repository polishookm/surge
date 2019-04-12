/* 
**  SurgeMessage provides basic functions for the synth to report messages back to the user
**  with a platform-neutral API. A platform-specific version of each implementation is
**  registered at startup.
**
**  You can call this with
**
**    Surge::UserInteractions::reportProblem()
**
**  or what not. 
*/

#pragma once

#include <string>
#include <atomic>
#include "SurgeError.h"

class SurgeGUIEditor;

namespace Surge
{

namespace UserInteractions
{

// Show the user an error dialog with an OK button; and wait for them to press it
void promptError(const std::string &message, const std::string &title,
                 SurgeGUIEditor *guiEditor = nullptr);

// And a convenience version which does the same from a Surge::Error
void promptError(const Surge::Error &error, SurgeGUIEditor *guiEditor = nullptr);

// Prompt the user with an OK/Cance
typedef enum MessageResult
{
    OK,
    CANCEL
} MessageResult;

MessageResult promptOKCancel(const std::string &message, const std::string &title,
                             SurgeGUIEditor *guiEditor = nullptr);

// Open a URL in a user-appropriate fashion
void openURL(const std::string &url);

// Open a folder in the system appropriate file browser (finder on macOS, explorer on win,
// etc)
void openFolderInFileBrowser(const std::string& folder);

};

};
