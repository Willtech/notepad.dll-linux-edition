# Notepad.sh (Linux Edition)

> A ritualistic text editor launcher that simulates the loading of every Windows DLL—just in case typing requires spiritual validation from Win32.

## 🧪 What It Does

- Loads a list of Windows `.DLL`s (symbolically)
- Launches a text editor (`nano`) once all DLLs are “loaded”
- Prints session completion message with mythic resonance

## 🔧 How to Use

```bash
chmod +x notepad.sh
./notepad.sh
```

## Additional notepad.dll.c

### Build

`gcc -o notepad.dll notepad.dll.c`  
or  
`make`  
`./notepad.dll --debug --superchook --log`

### Flags

## 🔧 Flags

- `--debug`: Print timestamps for each DLL load
- `--superchook`: Overlay ASCII chicken blessing
- `--log`: Write session details to `~/.notepad.dll.log`

