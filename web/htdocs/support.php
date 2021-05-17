<?php
$header_title = 'Support Questions and Answers';
include 'include/begin-head.php';
include 'include/begin-body.php';

$Q_A = array(

array(
'Q' => 'What is REDUCE?',

'A' => 'REDUCE is a Computer Algebra System. Think of it as a very
advanced programmable scientific calculator intended for solving
algebraic or symbolic problems. But it will also solve purely
numerical problems (exactly or approximately) and plot graphs.'),

array(
'Q' => 'Who is REDUCE intended for?',

'A' => '<p>REDUCE is intended for users who want to solve problems in
   mathematics, science and engineering at pre-university level and
   above, although it was originally developed for research in high
   energy (elementary particle) physics. But, as when using any kind
   of calculator or computer software, you may need to do quite a lot
   of work to get your problem into a form that REDUCE can
   solve. REDUCE (like most Computer Algebra Systems) is good at
   solving concrete problems (such as problems involving matrices with
   specified elements) and not so good as solving abstract problems
   (such as problems involving vector spaces of arbitrary
   dimension).</p>
<ol>
  <li>Casual users wishing to solve straightforward problems can use
    REDUCE interactively and may want to use some of
    the <a href="documentation.php#contributed">contributed REDUCE
    packages</a> that are not automatically loaded, which extend the
    domain of applicability of REDUCE beyond that of the core
    system.</li>
  <li>Users wishing to solve more complicated problems can use the
    REDUCE algebraic-mode programming language and may want to prepare
    REDUCE programs in files of source code to be read into
    REDUCE.</li>
  <li>Advanced users wishing to extend the domain of applicability of
    REDUCE may want to write programs using the REDUCE symbolic-mode
    programming language and compile them into new packages.</li>
  <li>Developers wishing to port REDUCE to other platforms or Lisp
    systems, incorporate REDUCE into other software, or modify REDUCE
    for their own purposes, and anyone interested in how REDUCE works,
    can access all the
    current <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">source
    code</a> for REDUCE and its support systems.</li>
</ol>'),

array(
'Q' => 'How can I obtain REDUCE?',

'A' => 'Go to the SourceForge
<a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE
project page</a>, click on the green Download button and install the
file that is downloaded. For more options (previous versions, other
platforms, etc.)  click on the
<a href="https://sourceforge.net/projects/reduce-algebra/files/">Files</a>
tab. For full and historical REDUCE-related source code (for REDUCE
itself, Lisp systems, user interfaces, documentation, etc.) click on
the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a>
tab to access the Subversion repository.
See <a href="obtaining.php">How to Obtain and Run REDUCE</a> for
further details.'),

array(
'Q' => 'How do I run REDUCE?',

'A' => 'Once you have installed REDUCE, you should see applications
named something like CSL REDUCE and/or PSL REDUCE in your application
menu; click on one of them. CSL REDUCE provides a graphical user
interface (by default) and PSL REDUCE provides a command-line
interface.  See <a href="obtaining.php">How to Obtain and Run
REDUCE</a> for further details.  But unless you are already familiar
with REDUCE you should probably first browse the REDUCE User&#39;s
Manual, either as <a href="../manual/manual.html">HTML</a>
or <a href="../manual/manual.pdf">PDF</a>.  A number
of <a href="books.php">published books</a> about REDUCE and related
topics are also available.'),

array(
'Q' => 'Why are there two versions of REDUCE?',

'A' => 'REDUCE runs on <a href="documentation.php">Standard Lisp</a>
and there are two versions of Standard Lisp that were developed
primarily to support REDUCE, namely <a href="versions.php">PSL and
CSL</a> (in that order chronologically). We only release distributions
of REDUCE based on these two Lisps, although REDUCE can be implemented
on other versions of Standard Lisp (and there is some experimental
code to do this in the
<a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/">repository</a>).'),

array(
'Q' => '<span id="interfaces">What user interfaces does REDUCE provide?</span>',

'A' => 'PSL REDUCE itself provides only a command-line interface
(CLI).  CSL REDUCE provides a graphical user interface (GUI) by
default, but it provides a command-line interface if started with
the <code>--nogui</code>
option.  <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>
is a GUI for running any command-line version of
REDUCE.  <a href="https://www.texmacs.org/">GNU TeXmacs</a> provides a
GUI for PSL and CSL REDUCE via a
<a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/texmacs/">plugin
for running REDUCE</a>.
<a href="https://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a>
provides a GUI for PSL and CSL REDUCE via
the <a href="reduce-ide/">REDUCE IDE</a> package.  The Redfront
versions of PSL and CSL REDUCE both provide the same consistent CLI
with input history and text colouring.  See
<a href="obtaining.php">How to Obtain and Run REDUCE</a> for further
details.  (There is also code in the repository for
<a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/xr/">XR</a>,
an X Window GUI for PSL, but it is not currently distributed as a
pre-built binary and is somewhat out of date.)'),

array(
'Q' => 'What start-up options does REDUCE provide?',

'A' => 'At the start of a REDUCE session, the system checks for the
existence of a user&apos;s <a href="/manual/manualse77.html">REDUCE
startup ﬁle</a>, and executes the REDUCE statements in it.  For CSL
REDUCE (only), running <code>redcsl --nogui --help</code> at a command
prompt lists the start-up options (assuming <code>redcsl</code> is on
your search path &ndash; see <a href="obtaining.php">How to Obtain and
Run REDUCE</a>).'),

array(
'Q' => 'How can I learn how to use REDUCE?',

'A' => 'The <strong>REDUCE User&#39;s
Manual</strong> <small>[ <a href="manual/manual.html">HTML</a>
| <a href="manual/manual.pdf">PDF</a> ]</small> is the obvious
starting point and there are also a number of
<a href="books.php">published books</a> covering various aspects of
REDUCE.  You may like to work through
the <a href="tutorials.php#lessons">REDUCE interactive lessons</a>.
Many of the
<a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/">REDUCE
packages</a> have one or more associated test files (with extension
<code>.tst</code>) and a corresponding log file (with
extension <code>.rlg</code>) containing the output from running the
test. These files, particularly the log files, provide instructive
examples of how to use REDUCE, although they were not written as
instructional material, are somewhat cryptic and assume the reader is
familiar with the problems addressed.  The
<a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/xmpl">xmpl</a>
directory in the REDUCE repository provides a convenient collection of
test and log files from many of the packages, although they may be out
of date.'),

array(
'Q' => 'How can I learn how REDUCE works and how to modify or extend it?',

'A' =>
'<a href="http://localhost/REDUCE/web/htdocs/lisp-docs/insidereduce.pdf"><strong>Inside
Reduce</strong></a>, the <strong>Symbolic Mode
Primer</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/primer.html">HTML</a>
| <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/primer.pdf">PDF</a>
]</small>, the <strong>Standard Lisp
Report</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/sl.html">HTML</a>
| <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/sl.pdf">PDF</a>
]</small>, the <strong>PSL Users
Manual</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/allman1.html">HTML</a>
| <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/allman1.pdf">PDF</a>
]</small> and
the <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/csl.html"><strong>CSL
Reference</strong></a> all provide useful background. Some of
the <a href="books.php">published books</a> on REDUCE discuss
algorithms and implementation, and the references in them will take
you further. Ultimately, you will have to read the
REDUCE <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">source
code</a>!'),

array(
'Q' => 'Why are there multiple REDUCE web sites?',

'A' => 'REDUCE is hosted on SourceForge, which provides a project site
and a project <strong>web</strong> site for each project; see the
SourceForge
<a href="https://sourceforge.net/p/forge/documentation/Docs%20Home/">Site
Documentation</a> for details.  The project site
(<a href="https://sourceforge.net/p/reduce-algebra/">https://sourceforge.net/p/reduce-algebra</a>
for REDUCE) hosts the software itself and its format is completely
controlled by SourceForge.  The project <strong>web</strong> site
(<a href="https://reduce-algebra.sourceforge.io">https://reduce-algebra.sourceforge.io</a>
for REDUCE) hosts any other information (such as this page) that the
REDUCE developers want to provide and its format is controlled by
them.  The REDUCE web site can also be accessed
as <a href="http://reduce-algebra.com/">reduce-algebra.com</a>, which
is the URL of the original REDUCE web site created by Tony Hearn when
REDUCE was a commercial product, but since 2017 it has been an alias
for <a href="https://reduce-algebra.sourceforge.io/">https://reduce-algebra.sourceforge.io</a>.
(The same URL but beginning with www,
namely <a href="http://www.reduce-algebra.com/">www.reduce-algebra.com</a>,
also works.)  Redlog, which is the REDUCE package for computing with
logic included in the standard distribution, has its
own <a href="http://www.redlog.eu/">independent web site</a>, which
includes the <a href="http://redlog.eu/reduce-wiki">Reduce Wiki</a>
that provides some general information about REDUCE.'),

array(
'Q' => 'How do I find out more about SourceForge?',

'A' => 'There is a link to the SourceForge
<a href="https://sourceforge.net/p/forge/documentation/Docs%20Home/">Site
Documentation</a> at the bottom of every SourceForge page, but this is
aimed more at developers than users and is not specific to REDUCE. The
most useful general user documentation is probably
the <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User
Account Information</a>.'),

array(
'Q' => 'Why should I register with SourceForge and log in?',

'A' => 'According to the SourceForge documentation
on <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User
Account Information</a>: Software can be downloaded from
SourceForge.net without registering an account. An account is needed
in order to participate in discussion forums, submit bug reports, and
join a project [as an administrator or
developer]. <a href="https://sourceforge.net/account/registration/">Register
a user account</a>.'),

array(
'Q' => 'How should I report a REDUCE bug?',

'A' => 'If you think you have found an error or omission in REDUCE, or
in any of its support systems or documentation, then please report it
using the bug tracker accessible via
the <a href="https://sourceforge.net/p/reduce-algebra/bugs/">Bugs</a>
tab on the REDUCE project page. You need to be logged in to
SourceForge to do this. Or, if you prefer, you can use
the <a href="mailto:reduce-algebra-developers@lists.sourceforge.net">reduce-algebra-developers
mailing list</a>, but you need to be registered with SourceForge to do
this.'),

array(
'Q' => 'What REDUCE online discussion fora are there?',

'A' => '<p>There are currently three REDUCE discussion fora &ndash;
  Open Discussion, Help, and Developers &ndash; accessible via
  the <a href="https://sourceforge.net/p/reduce-algebra/discussion/">Discussion</a>
  tab on the REDUCE project page. If you are not sure which is most
  appropriate, you can take a look at past discussions on each
  forum. You need to be logged in to SourceForge to post comments.</p>
<p>Note that SourceForge uses
  <a href="https://en.wikipedia.org/wiki/Markdown">markdown</a> syntax
  for input such as forum posts, which can have unexpected
  consequences if you think you are writing plain text! Please read
  the <a href="https://sourceforge.net/p/reduce-algebra/discussion/markdown_syntax">Formatting
  Help</a> if you are not familiar with markdown. In particular,
  markdown hijacks several mathematical operators for other purposes
  and, for example, if you want to use * to indicate multiplication
  then you either need to escape it as \* or use the HTML entity code
  &amp;ast;.</p>'),

array(
'Q' => 'What REDUCE mailing lists are available?',

'A' => 'We currently run only one mailing list, details of which are
accessible via the
<a href="https://sourceforge.net/p/reduce-algebra/mailman/">Mailing
Lists</a> tab on the REDUCE project page. Here you can access past
discussions and subscribe to the list. Although the list is called
&quot;reduce-algebra-developers&quot;, it is used for general
&quot;discussion of development, administration and support for
Reduce&quot;. In practice, it is probably used most by users asking
questions that developers try to answer. It is currently the main
support mechanism for REDUCE and can be used to report bugs, request
features, and discuss anything related to REDUCE. Developers also
occasionally use it for announcements. The list is low volume!'),

array(
'Q' => 'How can I receive updates on REDUCE by email?',

'A' => '<p>Log in to
  the <a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE
  project page</a> at SourceForge and then click on the Get Updates
  button (beside the green Download button).</p>
<p>To control all your email subscriptions, log in to SourceForge and
  then look at the Me link towards the top right-hand corner of most
  SourceForge pages. Hover over this, click on Account Settings in the
  drop-down menu and then select the Subscriptions tab.</p>'),

array(
'Q' => 'What is in the REDUCE code repository?',

'A' => '<p>You can browse the REDUCE source code repository most
  easily by clicking on the
  <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a>
  tab on the REDUCE project page. You are most likely to be interested
  in the code in the directory called trunk, so click
  on <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk">trunk</a>
  in the File column. Most directories contain a README file that is
  displayed at the bottom of the directory listing and gives some
  information about the purpose of the directory and/or how to use its
  contents. Most of the code relates to REDUCE itself or the Lisp
  systems used to implement it.</p>
<p>The <code>packages</code> directory contains most of the main code
  for REDUCE itself, which is written in RLISP and is (essentially)
  independent of the underlying Lisp system.  The <code>csl</code>
  and <code>psl</code> directories contain the main code for the two
  Lisp systems that support the distributed versions of REDUCE.
  The <code>jlisp</code>, <code>jslisp</code> and <code>vsl</code>
  directories contain experimental Lisp systems based on CSL.
  The <code>doc</code> directory contains the main documentation for
  REDUCE.  The <code>contrib</code> and <code>generic</code>
  directories contain contributed code that is not (yet) incorporated
  into the REDUCE distributions.  The <code>web</code> directory
  contains the code and content for the REDUCE web site (such as this
  page).</p>'),

array(
'Q' => 'How does REDUCE represent logarithms?',

'A' => '<p>As in most computer programming languages, the
  identifier <code>log</code> represents the natural logarithm
  function in REDUCE.  It is the fundamental logarithm function in
  REDUCE and works in both algebraic and numerical contexts.  It is
  used in the results of computations whenever any logarithms remain
  unevaluated.</p>
<p>In science and engineering, it is common to use the
  identifier <code>log</code> to represent logarithms to the base 10
  rather than natural logarithm, and REDUCE provides the
  identifier <code>log10</code> to represent logarithms to the base
  10.  REDUCE also provides the identifier <code>logb</code> to
  represent general logarithms to any base, which is specified by the
  second argument to the function.  The function <code>log10</code> is
  a special case of <code>logb</code> and both simplify to the
  function <code>log</code>.  For example, the REDUCE input</p>
<pre>{df(log(x),x), df(log10(x),x), df(logb(x,b),x)};</pre>
<p>
  evaluates to
</p>
<pre>  1       1          1
{---,-----------,----------}
  x   log(10)*x   log(b)*x</pre>
<p>In mathematics, it is common to use the identifier <code>ln</code>
  to represent the natural logarithm, and in REDUCE this identifier is
  defined to be an operator but with no algebraic properties. This
  means it can be used as a function that by default always evaluates
  to itself without being explicitly declared to be an operator. For
  example, by default all four expressions in the list</p>
<pre>{df(ln(x),x), int(ln(x),x), ln(1), ln(e)};</pre>
<p>remain unevaluated and are output exactly as they were
  input. However, a rule such as the following can be used to
  simplify <code>ln</code> to <code>log</code>:</p>
<pre>{df(ln(x),x), int(ln(x),x), ln(1), ln(e)} where ln ~x =&gt; log x;
  1
{---,x*(log(x) - 1),0,1}
  x</pre>
<p>A similar rule can be used to simplify <code>log</code>
  to <code>ln</code>, which might be useful for output:</p>
<pre>ws where log ~x => ln x;
  1
{---,x*(ln(x) - 1),0,1}
  x</pre>
<p>Such a computation, using <code>ln</code> for both input and
  output, must be done in two separate steps to avoid recursive
  simplification. A <code>let</code> statement can be used instead of
  a <code>where</code> clause, but then each <code>let</code> rule
  must be cleared before the other rule is applied, again to avoid
  recursive simplification.</p>
<p>The function <code>ln</code> can be used in numerical contexts when
  the switch <code>rounded</code> is on and will evaluate exactly
  as <code>log</code>. In fact, <code>ln</code> is an alias
  for <code>log</code> in symbolic mode, although not in algebraic
  mode.</p>'),

array(
'Q' => 'How can I control mathematical display in CSL REDUCE?',

'A' => '<p>You can turn off typeset display of mathematical output by
  turning off the switch <code>fancy</code>, either by using
  the <em>Switches</em> menu or by executing the command</p>
<p><code>off fancy;</code></p>
<p>This may provide a workaround in the unlikely event of a display
  glitch.  In addition, if you are having problems with the
  window-based version, or prefer a command-line version, you can run
  CSL REDUCE in command-line mode by starting it using the command</p>
<p><code>redcsl --nogui</code> or <code>redcsl -w</code></p>')

);
?>

<p>Click on a question to show (or hide) its answer.</p>
<div class="accordion" id="Q_A_accordion">
    <?php foreach ($Q_A as $index => $item): ?>
        <div class="card">
            <div class="card-header" id="heading<?=$index?>">
                <h5 class="mb-0">
	            <button class="btn btn-link collapsed" type="button"
                            data-toggle="collapse" data-target="#collapse<?=$index?>"
                            aria-expanded="false" aria-controls="collapse<?=$index?>">
	                <?=$index+1?>. <?=$item['Q']?>
	            </button>
                </h5>
            </div>
            <div id="collapse<?=$index?>" class="collapse"
                 aria-labelledby="heading<?=$index?>" data-parent="#Q_A_accordion">
                <div class="card-body">
	            <?=$item['A']?>
                </div>
            </div>
        </div>
    <?php endforeach; ?>
</div>

</div><!-- opened in begin-body.php -->

<?php
include 'include/footer.php';
?>

</body>
</html>
