#! /bin/sh

# Compare the (locally set up) sets of ARM and Intel ports. In some cases
# version numbers may differ and in bad cases a port may be installed for
# one but not the other - and this can help identify the situation so it
# can be addressed.

arm port installed | grep active | sed -e 's/+universal//' > /tmp/armports.txt
intel port installed | grep active > /tmp/intelports.txt

diff /tmp/armports.txt /tmp/intelports.txt | \
  sed -e 's/^>/Intel: /;s/^</ARM:   /;s/^[0-9]*[ac][0-9]*//;s/^---//;/^$/d'

