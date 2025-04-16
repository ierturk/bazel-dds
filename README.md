# Building and consuming FastDDS by Bazel Build Tools and Bazel Central Registry 
## Prerequisites
- Ubuntu WSL
- FastDDSGen V3 tool from eProsima (included in FastDDS installation)
- VS Code
- Bazel Build Tools
- Bazel Central Registry
## Libraries from Bazel Central Registry
- FastDDS
- FastCDR
## Building on Windows
Start a console
```bash
$ $ bazel run //:publisher
INFO: Analyzed target //:publisher (94 packages loaded, 15192 targets configured).
INFO: Found 1 target...
Target //:publisher up-to-date:
  bazel-bin/publisher
INFO: Elapsed time: 4.579s, Critical Path: 0.08s
INFO: 1 process: 126 action cache hit, 1 internal.
INFO: Build completed successfully, 1 total action
INFO: Running command line: bazel-bin/publisher
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
Published: Hello from Fast DDS!
```
Start another console
```bash
$ bazel run //:subscriber
INFO: Analyzed target //:subscriber (0 packages loaded, 2 targets configured).
INFO: Found 1 target...
Target //:subscriber up-to-date:
  bazel-bin/subscriber
INFO: Elapsed time: 0.330s, Critical Path: 0.02s
INFO: 1 process: 7 action cache hit, 1 internal.
INFO: Build completed successfully, 1 total action
INFO: Running command line: bazel-bin/subscriber
Waiting for data...
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
Received: Hello from Fast DDS!
```
# Clangd Support
To create file `compile_commands.json`
```
# with hedronvision/bazel-compile-commands-extractor
$ bazel run @hedron_compile_commands//:refresh_all

# or kiron1/bazel-compile-commands
$ bazel-compile-commands --bazelopt "--config=debug_target" --bazelopt "--config=opt_deps" --replace=-fno-canonical-system-headers= //...
```
## License
This project is licensed under the BSD 3-Clause License, which permits use, distribution, and modification with proper attribution, while disclaiming liability and warranty. See the [LICENSE](./LICENSE) file for full details.