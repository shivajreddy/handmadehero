# Create and go to build directory
$buildDir = Join-Path $PSScriptRoot "..\build" -Resolve
New-Item -Path $buildDir -ItemType Directory -Force | Out-Null
Push-Location $buildDir

# Compile the code
Write-Host "Compiling..."
cl -Zi ..\code\win32_handmade.cpp user32.lib gdi32.lib

# Check if compilation succeeded before running
if (Test-Path win32_handmade.exe) {
    Write-Host "Running the executable..."
    .\win32_handmade.exe
}
else {
    Write-Host "Compilation failed. Exe not found." -ForegroundColor Red
}

Pop-Location
