
# run this powershell script in the powershell session of handmadehero project, so that you can use 'cl' command
# which is loaded into the shell's session after running the vcvars64.bat file 

# Set the Visual Studio Environment
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat`" && set" | ForEach-Object {
    if ($_ -match "^(.*?)=(.*)$") {
        [System.Environment]::SetEnvironmentVariable($matches[1], $matches[2])
    }
}
