#! /bin/bash -v

./vsl -i Macfasl.img try-fasl.lsp | tee try-Macfasl.log
mv foo.b Macfoo.b

