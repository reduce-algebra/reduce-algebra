<?php
$page_title = 'Web REDUCE';
$header_title = 'Web REDUCE';
include '../include/begin-head.php';
?>
<style type="text/css">
 #OutputDiv, textarea {
     width: 100%
 }

 #OutputDiv {
     border: medium black solid;
     height: 25em;
     resize: vertical;
     overflow: auto;
 }

 #OutputDiv > pre {
     margin: 0;
 }

 div.labelling {
     margin-top: 5px;
     margin-bottom: 2px;
 }

 #buttons {
     margin-top: 5px;
     margin-bottom: 10px;
     display: flex;
     justify-content: space-evenly;
 }

 div.modal-body input[type="text"] {
     text-align: center;
     font-style: italic;
 }
</style>
<script>
 MathJax = {
     tex: {
         macros: { "*": "\\," }
     }
 };
</script>
<script async="async" src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>

<?php
include '../include/begin-body.php';
?>

<!-- Menu bar -->
<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <div class="container-fluid">
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavDropdown">
            <ul class="navbar-nav">
                <!-- View Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="ViewMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">View
                    </a>
                    <ul class="dropdown-menu" aria-labelledby="ViewMenuLink">
                        <li class="dropdown-item">
                            <input id="TypesetMathsCheckbox" type="checkbox" checked="checked" disabled="disabled" />
                            <label for="TypesetMathsCheckbox">Typeset Maths</label>
                        </li>
                        <li class="dropdown-item">
                            <input id="CentreTypesetMathsCheckbox" type="checkbox" checked="checked" />
                            <label for="CentreTypesetMathsCheckbox">Centre Typeset Maths</label>
                        </li>
                    </ul>
                </li>
                <!-- Templates Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="TemplatesMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Templates
                    </a>
                    <ul class="dropdown-menu" aria-labelledby="TemplatesMenuLink">
                        <li><a class="dropdown-item" href="#" data-bs-toggle="modal" data-bs-target="#DerivativeTemplate">Derivative...</a></li>
                        <li><a class="dropdown-item" href="#" data-bs-toggle="modal" data-bs-target="#IntegralTemplate">Integral...</a></li>
                    </ul>
                </li>
                <!-- Functions Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="FunctionsMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Functions
                    </a>
                    <ul class="dropdown-menu" aria-labelledby="FunctionsMenuLink">
                        <li><a class="dropdown-item" href="#" data-bs-toggle="modal" data-bs-target="#ExpLogFunctions">Exp, Log, Power, Root, etc...</a></li>
                    </ul>
                </li>
                <!-- Help Menu -->
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="HelpMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">Help
                    </a>
                    <ul class="dropdown-menu" aria-labelledby="HelpMenuLink">
                        <li><a class="dropdown-item" href="about.php" target="_blank" title="Opens in a new tab.">About Web REDUCE</a></li>
                        <li><a class="dropdown-item" href="UserGuide.php" target="_blank" title="Opens in a new tab.">Web REDUCE User Guide</a></li>
                        <li><a class="dropdown-item" href="/manual/manual.html" target="_blank" title="Opens in a new tab.">REDUCE Manual</a></li>
                    </ul>
                </li>
            </ul>
        </div>
    </div>
</nav>

<div class="labelling">
    <label for="OutputDiv"><strong>Input/Output Display</strong></label>
</div>
<div id="OutputDiv">
    REDUCE is loading. Please wait...
</div>
<div class="labelling">
    <label for="InputTextArea"><strong>Input Editor</strong></label>
</div>
<textarea id="InputTextArea" rows="3"></textarea>
<div id="buttons">
    <button id="EarlierButton" type="button" disabled="disabled" title="Select earlier keyboard input. Keyboard Shortcut: Control+UpArrow.">▲ Earlier Input</button>
    <button id="SendButton" type="button" title="Send the input above to REDUCE, terminating with a semicolon if necessary. Keyboard Shortcut: Control+Enter. (Also hold Shift to prevent auto-termination.)">Send Input</button>
    <button id="LaterButton" type="button" disabled="disabled" title="Select later keyboard input. Keyboard Shortcut: Control+DownArrow.">▼ Later Input</button>
</div>
<a href="https://www.mathjax.org">
    <img title="Powered by MathJax"
         src="https://www.mathjax.org/badge/badge.gif"
         alt="Powered by MathJax" style="float: right" />
</a>

    </div><!-- opened in begin-body.php -->

    <?php include '../include/footer.php'; ?>

    <script src="Main.js"></script>
    <script src="InputEditor.js"></script>

    <!-- Modal Dialogues -->
    <?php include './DerivativeTemplate.inc' ?>
    <?php include './IntegralTemplate.inc' ?>
    <?php include './ExpLogFunctions.inc' ?>
</body>
</html>
