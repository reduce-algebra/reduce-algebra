<?php
$gnuplot = (str_contains($_SERVER['QUERY_STRING'], 'gnuplot'));
$debug = (str_contains($_SERVER['QUERY_STRING'], 'debug'));
$page_title = 'Web REDUCE';
$header_title = 'Web REDUCE';
include '../include/begin-head.php';
?>

<style type="text/css">
    /* REDUCE */

    #IODisplayIframe,
    #InputDiv,
    #plot-div {
        width: 100%
    }

    #IODisplayIframe {
        border: medium solid black;
        height: 25em;
        resize: vertical;
        /* Works in Chrome but not Firefox; see
        https://stackoverflow.com/questions/8117761/how-can-i-make-an-iframe-resizable */
    }

    #InputDiv {
        font-family: var(--bs-font-monospace);
        /* Bootstrap pre default */
        border: thin solid black;
        height: 7em;
        resize: vertical;
        padding: 2px;
        overflow-y: auto;
        white-space: pre-wrap;
    }

    #InputDiv:focus {
        background-color: white;
        outline: medium outset blue;
    }

    div.labelling {
        font-weight: bold;
        margin-top: 5px;
        margin-bottom: 2px;
    }

    #buttons {
        margin-top: 5px;
        margin-bottom: 10px;
        display: flex;
        justify-content: space-evenly;
    }

    #plot-div {
        border: thin solid black;
    }

    #gnuplot-image {
        width: 600px;
        margin-left: auto;
        margin-right: auto;
        background-color: white;
    }

    div.modal-body input[type="text"] {
        text-align: center;
        font-style: italic;
    }

    div.function-templates {
        display: grid;
        grid-row-gap: 20px;
        align-items: center;
        justify-content: center;
    }

    div.function-templates.three-col {
        grid-template-columns: repeat(auto-fill, 250px);
    }

    div.function-templates.two-col {
        grid-template-columns: repeat(auto-fill, 340px);
    }

    div.function-templates>div.selected {
        outline: auto blue medium;
    }

    div.function-templates p {
        margin-bottom: 0;
    }

    .fs-big {
        font-size: 150%;
    }

    .fs-normal {
        font-size: medium;
    }

    /* Gnuplot */
    #plot-window {
        margin-bottom: 1rem;
    }

    #input {
        height: 30vh;
        /* % of viewport height */
        overflow: scroll;
        border: solid black medium;
    }
</style>

<?php include '../include/begin-body.php'; ?>

<!-- Menu bar -->
<nav id="Menubar" class="navbar navbar-expand-lg navbar-light bg-light">
    <div class="container-fluid">
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavDropdown">
            <ul class="navbar-nav">
                <!-- REDUCE Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle disabled" href="#" id="REDUCEMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">REDUCE</a>
                    <ul class="dropdown-menu" aria-labelledby="REDUCEMenuLink">
                        <li><button id="StartREDUCEMenuItem" class="dropdown-item" type="button">Start REDUCE</button>
                        </li>
                        <li><button id="LoadPackagesMenuItem" class="dropdown-item" data-bs-toggle="modal" data-bs-target="#LoadPackagesDialogue" type="button">Load Packages&hellip;</button></li>
                        <li><button id="StopREDUCEMenuItem" class="dropdown-item" type="button">Stop REDUCE</button>
                        </li>
                        <li><button id="RestartREDUCEMenuItem" class="dropdown-item" type="button">Restart
                                REDUCE</button></li>
                        <li><button id="ClearDisplayMenuItem" class="dropdown-item" type="button">Clear I/O
                                Display</button></li>
                        <li><button id="PrintDisplayMenuItem" class="dropdown-item" type="button">Print I/O
                                Display</button></li>
                    </ul>
                </li>
                <!-- File Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="FileMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">File</a>
                    <ul class="dropdown-menu" aria-labelledby="FileMenuLink">
                        <li class="dropdown-item">
                            <input id="EchoFileInputCheckbox" type="checkbox" checked="checked" />
                            <label for="EchoFileInputCheckbox">Echo File Input</label>
                        </li>
                        <li><button id="InputFileMenuItem" class="dropdown-item" type="button">Input from
                                File&hellip;</button></li>
                        <li>
                            <hr class="dropdown-divider">
                        </li>
                        <li><button id="OutputFileMenuItem" class="dropdown-item" type="button">Output to
                                File&hellip;</button></li>
                        <li><button id="OutputHereMenuItem" class="dropdown-item" type="button">Output Here</button>
                        </li>
                        <li><button id="OutputOpenMenuItem" class="dropdown-item" type="button">Output to Open
                                File</button></li>
                        <li><button id="ShutFileMenuItem" class="dropdown-item" type="button">Shut Output File</button>
                        </li>
                    </ul>
                </li>
                <!-- View Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="ViewMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">View</a>
                    <ul class="dropdown-menu" aria-labelledby="ViewMenuLink">
                        <li class="dropdown-item">
                            <input id="FullWindowCheckbox" type="checkbox" />
                            <label for="FullWindowCheckbox">Full Window</label>
                        </li>
                        <hr class="dropdown-divider">
                        <li class="dropdown-item">
                            <input id="IOColouringCheckbox" type="checkbox" checked="checked" />
                            <label for="IOColouringCheckbox">I/O Colouring</label>
                        </li>
                        <li class="dropdown-item">
                            <input id="TypesetMathsCheckbox" type="checkbox" checked="checked" disabled="disabled" />
                            <label for="TypesetMathsCheckbox">Typeset Maths</label>
                        </li>
                        <li class="dropdown-item">
                            <input id="CentreTypesetMathsCheckbox" type="checkbox" checked="checked" />
                            <label for="CentreTypesetMathsCheckbox">Centre Typeset Maths</label>
                        </li>
                        <li>
                            <hr class="dropdown-divider">
                        </li>
                        <li class="dropdown-item">
                            <input id="MatchDelimsCheckbox" type="checkbox" checked="checked" />
                            <label for="MatchDelimsCheckbox">Highlight Matching Delimiters</label>
                        </li>
                    </ul>
                </li>
                <!-- Templates Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="TemplatesMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Templates</a>
                    <ul class="dropdown-menu" aria-labelledby="TemplatesMenuLink">
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#DerivativeTemplate" type="button">Derivative&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#IntegralTemplate" type="button">Integral&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#LimitTemplate" type="button">Limit&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#SumProdTemplate" type="button">Sum or Product&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#MatrixTemplate" type="button">Matrix&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#SolveTemplate" type="button">Solve Equation(s)&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#ODESolveTemplate" type="button">Solve an ODE&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#ForTemplate" type="button">For Statement&hellip;</button></li>
                    </ul>
                </li>
                <!-- Functions Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="FunctionsMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Functions</a>
                    <ul class="dropdown-menu" aria-labelledby="FunctionsMenuLink">
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#ExpLogFunctions" type="button">Exp, Log, Power, Root, etc&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#GammaEtcFunctions" type="button">Gamma &amp; Beta Functions, etc&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#IntegralFunctions" type="button">Integral Functions&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#AiryBesselFunctions" type="button">Airy &amp; Bessel Functions, etc&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#StruveEtcFunctions" type="button">Struve &amp; Kummer Functions, etc&hellip;</button></li>
                        <li><button class="dropdown-item" data-bs-toggle="modal" data-bs-target="#OrthoPolyFunctions" type="button">Classical Orthogonal Polynomials&hellip;</button></li>
                    </ul>
                </li>
                <!-- Help Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="HelpMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Help</a>
                    <ul class="dropdown-menu" aria-labelledby="HelpMenuLink">
                        <li><a class="dropdown-item" href="about.php" target="_blank" title="Opens in a new tab.">About
                                Web REDUCE</a></li>
                        <li><a class="dropdown-item" href="UserGuide.php" target="_blank" title="Opens in a new tab.">Web REDUCE User Guide</a></li>
                        <li><a class="dropdown-item" href="/manual/manual.html" target="_blank" title="Opens in a new tab.">REDUCE Manual</a></li>
                    </ul>
                </li>
            </ul>
        </div>
    </div>
</nav>

<div class="labelling">
    <label for="IODisplayIframe">Input/Output Display</label>
</div>
<iframe id="IODisplayIframe"></iframe>

<div class="labelling">
    <label for="InputDiv">Input Editor</label>
</div>
<div id="InputDiv" contenteditable="true" spellcheck="false"></div>
<div id="buttons">
    <button id="EarlierButton" type="button" disabled="disabled" title="Select earlier keyboard input. Keyboard Shortcut: Control+UpArrow.">▲ Earlier Input</button>
    <button id="SendInputButton" type="button" title="Send the input above to REDUCE, terminating with a semicolon if necessary.
Keyboard Shortcut: Control+Enter. (Also hold Shift to prevent auto-termination.)">Send Input</button>
    <button id="PlotButton" type="button" title="Send the input above to Gnuplot. Keyboard Shortcut: Control+Enter.">Gnuplot</button>
    <button id="LaterButton" type="button" disabled="disabled" title="Select later keyboard input. Keyboard Shortcut: Control+DownArrow.">▼ Later Input</button>
    <?php if ($gnuplot) : ?>
        <button id="toggle-plot-display-button" type="button" onclick="togglePlotWindowDisplay()">Show Plot Window (Below)</button>
    <?php endif; ?>
</div>

<?php if ($gnuplot) : ?>
    <!-- Web Gnuplot -->
    <div id="plot-window">
        <div class="labelling">
            <label for="plot-div">
                Plot Display
                <span style="font-weight: normal">(<span id="gnuplot-version"></span>)</span>
            </label>
        </div>
        <div id="plot-div">
            <div id="gnuplot-image">
                <!-- The default plot size in standalone mode is 600 by 400 pixels. -->
                <canvas id="draw_plot_on_canvas" width="600" height="400">
                    No support for HTML 5 canvas element
                </canvas>
            </div>
        </div>
    </div>
    <script>
        var $gnuplot = true;
    </script>
<?php else : ?>
    <script>
        var $gnuplot = false;
    </script>
<?php endif; ?>

</div><!-- opened in begin-body.php -->

<?php include '../include/footer.php'; ?>

<!-- REDUCE Libraries -->

<!-- Modal Dialogues -->
<script type="module" src="generated/TempFuncs.js"></script>
<script type="module" src="generated/Templates.js"></script>
<?php
include './LoadPackagesDialogue.inc';

include './TempFuncs.inc';
include './Templates/DerivativeTemplate.inc';
include './Templates/IntegralTemplate.inc';
include './Templates/LimitTemplate.inc';
include './Templates/SumProdTemplate.inc';
include './Templates/MatrixTemplate.inc';
include './Templates/SolveTemplate.inc';
include './Templates/ODESolveTemplate.inc';
include './Templates/ForTemplate.inc';

include './Functions/ExpLogFunctions.inc';
include './Functions/GammaEtcFunctions.inc';
include './Functions/IntegralFunctions.inc';
include './Functions/AiryBesselFunctions.inc';
include './Functions/StruveEtcFunctions.inc';
include './Functions/OrthoPolyFunctions.inc';
?>

<!-- Main User Interface -->
<script type="module" src="generated/Main.js"></script>
<script type="module" src="generated/InputEditor.js"></script>
<script type="module" src="generated/FileMenu.js"></script>

<?php if ($gnuplot) : ?>
    <!-- Gnuplot Libraries -->
    <script src="generated/run-gnuplot.js"></script>
    <script src="gnuplot/gnuplot.js"></script>
    <script src="gnuplot/termjs/canvastext.js"></script>
    <script src="gnuplot/termjs/gnuplot_common.js"></script>
    <script src="gnuplot/termjs/gnuplot_dashedlines.js"></script>
<?php endif; ?>

</body>

</html>