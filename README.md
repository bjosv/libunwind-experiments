# libunwind-experiments

This repo contains experiments using [libunwind](https://www.nongnu.org/libunwind/).

Some programs requires https://github.com/libunwind/libunwind/pull/299

`unw_get_proc_name_by_ip__dynamic` not working as expected, due to:
https://www.corsix.org/content/libunwind-dynamic-code-x86-64


## Documentation in libunwind

### Installation

The build requires latex2man, install using
`sudo apt install texlive-extra-utils`

Use latex2man version 1.24 to avoid excessive changes:
https://www.informatik-vollmer.de/software/latex2man-1.24.tar.gz
