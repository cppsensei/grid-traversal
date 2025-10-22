$ErrorActionPreference = "Stop"

$BUILD_DIR = "build"
$INSTALL_DIR = Join-Path -Path (Get-Location) -ChildPath "install"

if (Test-Path $BUILD_DIR) {
    Remove-Item -Recurse -Force $BUILD_DIR
}

New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null
Set-Location $BUILD_DIR

cmake .. -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DBUILD_TESTING=OFF

cmake --build . -- -j $( [System.Environment]::ProcessorCount )
cmake --install . --prefix $INSTALL_DIR
