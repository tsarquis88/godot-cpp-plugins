### Compile godot-cpp
```
godot --gdnative-generate-json-api api.json
cd godot-cpp
scons platform=<platform> generate_bindings=yes use_custom_api_file=yes custom_api_file=../api.json -j4
cd ..
```
Replacing `platform` with windows, linux or osx depending on your OS.
### Compile plugins
```
scons platform=<platform>
```
