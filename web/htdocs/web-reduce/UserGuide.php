<?php
$page_title = 'Web REDUCE User Guide';
$header_title = 'Web REDUCE User Guide';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>
<h2>Contents</h2>
<ul>
    <li><a href="#MainPage">The Main Page</a></li>
    <li><a href="#REDUCEMenu">The REDUCE Menu</a></li>
    <li><a href="#FileMenu">The File Menu</a></li>
    <li><a href="#ViewMenu">The View Menu</a></li>
    <li><a href="#TemplatesMenu">The Templates Menu</a></li>
    <li><a href="#FunctionsMenu">The Functions Menu</a></li>
    <li><a href="#HelpMenu">The Help Menu</a></li>
    <li><a href="#QueryString">Controlling Web REDUCE via the URL Query String</a></li>
</ul>

<h2 id="MainPage">The Main Page</h2>

<p>
    Web REDUCE normally starts loading as soon as its main page is
    opened and starts running as soon as it has loaded, which should
    be almost instantaneous except for the first time you run it in a
    particular browser or after an update to the Web REDUCE engine, in
    which case there may be a noticeable pause. Web REDUCE will stop
    when you close its main page; it is not necessary to explicitly
    terminate REDUCE.  However, you can stop and start Web REDUCE by
    using the <a href="#REDUCEMenu">REDUCE Menu</a>, and stop Web
    REDUCE by executing the command <code>BYE</code> or <code>QUIT</code>,
    as usual.  To fully reset and restart Web REDUCE just reload its
    main page.
</p>
<p>
    The Web REDUCE main page consists of a menu bar and two panes, one
    above the other. The top pane displays all the REDUCE input and
    output in the current session. It is read-only. The bottom pane is
    an input editor that supports all the standard keyboard and
    mouse-based editing facilities normally provided by your platform.
    Both panes display vertical scroll bars when necessary. The top
    pane wraps input when possible and displays a horizontal scroll
    bar when necessary; text wraps in the input editor. The input
    editor can be resized vertically by dragged the bottom right-hand
    corner, and in Chromium-based browsers the I/O display can
    similarly be resized vertically by dragged the bottom right-hand
    corner. Input text can always be copied from the top pane; plain
    text output can also be copied but typeset mathematical output
    cannot currently be copied in such a way that it can be re-input
    into REDUCE.
</p>
<p>
    You type (or paste) REDUCE input into the input editor pane, edit
    it as necessary, and then click on the <em>Send Input</em>
    button, which sends the input to REDUCE and echos it in the top
    pane. This clears the input editor, but you can scroll through
    previous input (entered via the input editor) using the
    <em>Earlier Input</em> and <em>Later Input</em> buttons.
    Scrolling to input later than the last previous input clears the
    input editor pane back to its state before you started scrolling.
</p>
<p>
    When keyboard focus is in the input editor pane, the following
    keyboard shortcuts are active:
</p>
<table class="table">
    <thead>
        <tr>
            <th>Keyboard Shortcut</th>
            <th>Action</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><em>Control+Enter</em></td>
            <td>Send Input (auto-terminated)</td>
        </tr>
        <tr>
            <td><em>Control+Shift+Enter</em></td>
            <td>Send Input (not auto-terminated)</td>
        </tr>
        <tr>
            <td><em>Control+UpArrow</em></td>
            <td>Earlier Input</td>
        </tr>
        <tr>
            <td><em>Control+DownArrow</em></td>
            <td>Later Input</td>
        </tr>
    </tbody>
</table>
<p>
    where <em>Enter</em> is the <em>Return</em> or <em>Enter</em>
    key and <em>UpArrow</em> / <em>DownArrow</em> are the cursor up /
    down keys, respectively.
</p>
<p>
    Sending input to REDUCE strips any trailing white space and
    normally auto-terminates it by adding a semicolon if there was no
    final terminator. However, holding the <em>Shift</em> key while
    clicking on the <em>Send Input</em> button or pressing
    <em>Control+Enter</em> suppresses auto-termination.
</p>
<p>
    You can edit previous input recalled into the input editor as
    necessary and then send it to REDUCE. Input can be multi-line, in
    which case REDUCE processes all the lines together. The
    <em>Send Input</em> action is disabled until REDUCE is running,
    and the <em>Earlier Input</em> and <em>Later Input</em> actions
    are disabled unless there is earlier or later input, respectively.
</p>

<h2 id="REDUCEMenu">The REDUCE Menu</h2>
<p>
    The <em>REDUCE</em> menu provides the following items:
</p>
<h3>Start REDUCE</h3>
<p>
    Selecting this item clears the Input/Output Display and then
    starts Web REDUCE, which displays the usual CSL REDUCE start-up
    message.  It is disabled if Web REDUCE is already running.
</p>
<h3>Stop REDUCE</h3>
<p>
    Selecting this item stops Web REDUCE and displays the message
    "REDUCE stopped".  It is disabled if Web REDUCE is not running.
    Executing either of the usual commands <code>BYE</code> or
    <code>QUIT</code> should have exactly the same effect.
</p>
<h3>Clear I/O Display</h3>
<p>
    Selecting this item clears the Input/Output Display, but has no
    other effect.
</p>
<h3>Print I/O Display</h3>
<p>
    Selecting this item prints the Input/Output Display, but has no
    other effect.  It uses the normal printing facilities provided by
    the web browser, and prints the whole of the current contents of
    the Input/Output Display, not just the visible part.  The printed
    version should look more-or-less identical to what is shown on the
    screen, including colour and typeset mathematics if enabled. This
    is, of course, subject to a suitable printer setup, but it seems
    to work well on Windows 10 outputting to a PDF file.
</p>

<h2 id="FileMenu">The File Menu</h2>
<p>
    The <em>File</em> menu uses the experimental
    <a href="https://web.dev/file-system-access/">File System Access API</a>,
    which is only supported by
    <a href=https://en.wikipedia.org/wiki/Chromium_(web_browser)>Chromium-based browsers</a>
    on desktop platforms.  Hence, this menu is currently available in
    desktop browsers such as Chrome, Edge, and Opera, but not in
    Firefox.  It is enabled only when Web REDUCE is running, and
    provides the following items:
</p>
<h3>Input from Files&hellip;</h3>
<p>
    Selecting this item displays a file picker that allows one or more
    files to be selected and input into Web REDUCE.
    <strong>Beware that the effect of this is as if the file contents
        were typed or pasted into the input editor and then sent to
        Web REDUCE all together.  Hence, Web REDUCE echoes all the
        file input first and then displays all the resulting output.
        By contrast, the REDUCE IN command interleaves input and
        output.  Providing a better emulation of the REDUCE IN command
        is a high priority!</strong>
</p>
<h3>Output to File&hellip;</h3>
<p>
    Selecting this item displays a file picker that allows a file to
    be selected and output from Web REDUCE to be sent to it. It also
    disables typeset mathematics output temporarily so that the
    contents of the output file should be plain ASCII text.  This is
    essentially how the REDUCE OUT command works. However, Web REDUCE
    currently supports only one open output file at a time and there
    is no facility to switch output between an open output file and
    the screen.
</p>
<h3>Shut Output File</h3>
<p>
    Selecting this item closes the current output file and directs
    output back to the screen.  It is enabled only when an output file
    is in effect.  This is essentially how the REDUCE SHUT command
    works, except that the latter requires that you specify the file
    to shut.
</p>

<h2 id="ViewMenu">The View Menu</h2>
<p>
    The <em>View</em> menu provides the following items:
</p>
<h3>I/O Colouring</h3>
<p>
    Selecting this item causes Web REDUCE to display input coloured
    red and output coloured blue in the Input/Output Display;
    otherwise the default colour (normally black) is used for both
    input and output.
</p>
<h3>Typeset Maths</h3>
<p>
    Selecting this item causes Web REDUCE to display algebraic-mode
    mathematical output more-or-less as it would be typeset. Output
    display will be significantly faster when Typeset Maths is turned
    off. Typeset output should appear very similar to that displayed
    by the CSL REDUCE GUI and <a href="https://www.texmacs.org/">TeXmacs</a>
    since it is generated by the same REDUCE code, although in Web
    REDUCE it is displayed using the
    <a href="https://www.mathjax.org">MathJax</a> JavaScript library.
    Right-clicking on typeset math output pops up the MathJax context
    menu.
</p>
<h3>Centre Typeset Maths</h3>
<p>
    Selecting this item causes Web REDUCE to display typeset maths
    centred horizontally; otherwise it is left justified.
</p>

<h2 id="TemplatesMenu">The Templates Menu</h2>

<p>
    The <em>Templates</em> menu facilitates construction of structured
    expressions and statements whose syntax might not be immediately
    obvious, especially to a novice. The template dialogues all
    provide hyperlinks to the key sections of the HTML version of the
    REDUCE Manual, which open in a new tab in your web browser. The
    dialogues all provide two buttons that apply the filled-in
    template: the <em>Edit</em> button inserts the template output
    into the input editor at the current cursor position, replacing
    any selected text; the <em>Evaluate</em> button sends the template
    output directly to REDUCE for evaluation, adding a terminator just
    as the <em>Send Input</em> button does. These buttons also close
    the dialogue. To close a template dialogue explicitly, click on
    the <em>Close</em> button.
</p>
<p>
    If the template represents an operator with a primary operand then
    this defaults to <em>ws</em>, which is convenient for simple
    interactive calculations, but it can be changed to anything. The
    templates provide some minimal input validation: for example, if
    an element must be an explicit number (rather than a variable that
    must evaluate to a number), the template will check this and
    report an error immediately an inappropriate character is entered.
    The template checks that all input has been provided that is
    required for valid REDUCE syntax.
</p>
<p>
    Templates remember their previous input, but clicking on the
    <em>Reset</em> button resets them to their initial state when Web
    REDUCE was first started.
</p>
<p>
    These templates are intended only for creating simple structures,
    but they can form the basis for arbitrarily complex structures if
    they are entered into the input editor for further editing. The
    fields of expression templates display minimal formatting intended
    to hint at how such an expression would normally be typeset.
</p>
<p>
    The <em>Templates</em> menu provides the following items:
</p>
<h3>Derivative&hellip;</h3>
<p>
    This template supports (partial) differentiation involving up to
    three independent variables, each to arbitrary order. The orders
    must be explicit positive integers and the total order
    automatically updates to reflect the number of independent
    variables and their orders. If an order is omitted then it
    defaults to 1. At least one independent variable is required but
    others are optional. The dependent variable defaults to
    <em>ws</em> and the first independent variable defaults to
    <em>x</em>, but both can be changed.
</p>
<h3>Integral&hellip;</h3>
<p>
    This template supports both indefinite and definite integration: if
    both limits are omitted then the integral is indefinite; if both
    limits are specified then the integral is definite. The integrand
    defaults to <em>ws</em> and the integration variable defaults
    to <em>x</em>, but both can be changed.
</p>
<p>
    By default, the template provides a single integral, but if you
    enter another integration variable in a box to the right of the
    primary integration variable then an additional integral appears
    wrapping the previous integral, thus supporting double and triple
    integrals. Matching &int; and <em>d</em> symbol pairs have the
    same colour (blue, green or red) to facilitate adding limits to
    the right &int; symbol.
</p>

<h2 id="FunctionsMenu">The Functions Menu</h2>

<p>
    The <em>Functions</em> menu facilitates access to some of the
    mathematical functions provided by REDUCE via dialogue boxes
    similar to those provided by the <em>Templates</em> menu. The
    function dialogues all provide hyperlinks to the key sections of
    the HTML version of the REDUCE Manual, which open in a new tab in
    your web browser. Hover over a function name to pop up a tooltip
    that gives a hint at its definition, which often uses linearlized
    mathematical notation similar to LaTeX (but without any
    backslashes).
</p>
<p>
    The function dialogue boxes provide a grid of function
    templates. Click on the radio button to the left of the
    function you want to use. The templates display the conventional
    notation used for the functions but with editable text fields
    holding the function arguments. The default arguments are
    either <em>ws</em>, where this seems appropriate, or the
    conventional variable names.
</p>
<p>
    The <em>Functions</em> menu provides the following items:
</p>
<h3>Exp, Log, Power, etc&hellip;</h3>
<p>
    This provides the exponential function, various logarithms, power
    and roots (surds or radicals), factorial and binomial
    coefficients, and the hypot and atan<sub>2</sub> functions.
</p>
<h3>Gamma &amp; Beta Functions, etc&hellip;</h3>
<p>
    This provides the Gamma, Beta, digamma, polygamma, normalized
    incomplete Gamma and Beta, and dilogarithm functions, Pochhammer's
    symbols, binomial coefficients and the Riemann zeta function.
</p>

<h2 id="HelpMenu">The Help Menu</h2>

<p>
    The <em>Help</em> menu provides the following items, which all
    open in a new browser tab:
</p>
<h3>Web REDUCE User Guide</h3>
<p>
    This document.
</p>
<h3>REDUCE Manual</h3>
<p>
    The HTML version of the REDUCE Manual.
</p>
<h3>About Run-REDUCE</h3>
<p>
    Information about Web REDUCE, including its limitations.
</p>

<h2 id="QueryString">Controlling Web REDUCE via the URL Query String</h2>

<ul>
    <li>
        If the main Web REDUCE page is opened with the query string
        <code>?noautorun</code>, i.e. <code>/web-reduce?noautorun</code>,
        then Web REDUCE is not automatically run, but the web page is
        otherwise set up normally.
    </li>
    <li>
        If the main Web REDUCE page is opened with the query string
        <code>?debug</code>, i.e. <code>/web-reduce?debug</code>, then
        input to and output from REDUCE is logged to your web browser's
        JavaScript console (by calling <code>console.log()</code>).
        This facility is intended for developers.
    </li>
</ul>

<address>Francis Wright, September 2021</address>
</div><!-- opened in begin-body.php -->
<?php include '../include/footer.php'; ?>
</body>

</html>
