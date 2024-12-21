## Initial Configuration
```bash
project-root-dir $ cmake -S . -B ./build
```

## Compiling
```bash
project-root-dir $ cmake --build ./build
```

## Running
- Linux
  ```bash
  project-root-dir $ ./build/{somewhere-dir}/the-app-0.0.0
  ```
- Windows
  ```bash
  project-root-dir > .\build\{somewhere-dir}\the-app-0.0.0.exe
  ```


## Troubleshooting
- Try to re-initialized the setup, but before doing it, try to forcely delete the previous **build** dir.
  - ### Linux
      ```bash
      project-root-dir $ rm -rf ./build
      ```
  - ### Windows Powershell
      ```bash
      project-root-dir > remove-item -recurse -force ".\build"
      ```

## With custom script file **(clean and build)**
- ### Linux
  ```bash
  project-root-dir $ ./project.sh --clean --build build
  ```
- ### Windows
  ```bash
  project-root-dir > .\project.bat --clean --build build
  ```
