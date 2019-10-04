<?php  // -*-mhtml-*-

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Building REDUCE on Microsoft Windows');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
  td, th {
      padding: 2px 5px;
      border: solid 1px;
  }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Building REDUCE on Microsoft Windows');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>These instructions outline how to build REDUCE from the source code
    on Microsoft Windows.  Please note that this is fairly
    time-consuming, not easy for the uninitiated, and we currently
    explicitly support building
    using <a href="http://cygwin.com">Cygwin</a> only, although the
    resulting compiled version of REDUCE will be a native Windows
    application that does not require Cygwin to run. You can download
    the source code from the REDUCE project page as either:</p>
<ul>
  <li>a pre-packaged distribution via
    the <a href="https://sourceforge.net/projects/reduce-algebra/files/">Files</a>
    tab, which is easiest and should give you a tested
    &quot;snapshot&quot;;</li>
  <li>files from the subversion repository via
    the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a>
    tab, which will give you the latest bug fixes and updates but may
    not be fully tested and so may not be completely stable.</li>
</ul>

<h2>The Cygwin build environment</h2>
<p>The build environment on Windows is currently assumed to
be <a href="http://cygwin.com/">Cygwin</a>, which provides a very
similar environment to Linux: Linux consists of GNU software running
on a Linux kernel, whereas Cygwin consists of GNU software running on
a Windows kernel via a Unix emulation layer provided by the Cygwin
dll. <a href="https://www.redhat.com/en">Red Hat, Inc.</a> supports
both Cygwin and its own distribution of Linux.</p>
<p>You need to have a sufficiently
complete <a href="http://cygwin.com/">Cygwin</a> installation,
including the tools required to obtain and unpack the source code
files and the tools required to build using
the <a href="http://www.mingw.org/">MinGW (Minimalist GNU for
Windows)</a> environment. If the build process fails in any
non-obvious way then it probably means that you are missing some
necessary build tool. Once you have a suitable Cygwin installation,
building REDUCE is very similar to the procedure on other
platforms. For the time being, please see the general guidance
on <a href="/downloading.php">Downloading REDUCE from
SourceForge</a>.</p>
<p>Here is a tentative list of the Cygwin package you need to build
REDUCE, but please note that we don't guarantee this list to be either
sufficient or necessary!</p>
<table>
  <caption>
    Required Cygwin packages
  </caption>
  <tr>
    <th scope="col">Package</th>
    <th scope="col">Comment</th>
  </tr>
  <tr>
    <td>autoconf</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>automake</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>(bash)</td>
    <td>installed anyway</td>
  </tr>
  <tr>
    <td>bintools</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>bison</td>
    <td>not used via regular makescripts</td>
  </tr>
  <tr>
    <td>bzip2</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>diffutils</td>
    <td>?needed?</td>
  </tr>
  <tr>
    <td>flex</td>
    <td>not used via regular makescripts</td>
  </tr>
  <tr>
    <td>gcc-g++</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>gcc-mingw-g++</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>gzip</td>
    <td>probably!</td>
  </tr>
  <tr>
    <td>libncurses-devel</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>libtool</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>make</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>patch</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>patchutils</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>sed</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>subversion</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>tar</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td>tetex</td>
    <td>to process the documentation</td>
  </tr>
  <tr>
    <td>unzip</td>
    <td>&nbsp;</td>
  </tr>
</table>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
