#! /bin/bash -v

./vsl -i Winfasl.img try-fasl.lsp | tee try-Winfasl.log
mv foo.b Winfoo.b

