### Initial Setup
```bash
project-root-dir $ cmake -S . -B ./build
```

### Compiling
```bash
project-root-dir $ cmake --build ./build
```

### Running
```bash
project-root-dir $ ./build/{somewhere-dir}/the-app-0.0.0.exe
```

### Troubleshooting
- Try to re-initialized the setup, before doing it, try to forcely delete the previous **build** dir.
    - Windows Powershell
      ```bash
        project-root-dir > remove-item -recurse -force ".\build"
        ```
    - Linux
        ```bash
        project-root-dir $ rm -rf ./build
        ```