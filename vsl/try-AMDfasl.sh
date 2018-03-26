#! /bin/bash -v

./vsl -i AMDfasl.img try-fasl.lsp | tee try-AMDfasl.log
mv foo.b AMDfoo.b

