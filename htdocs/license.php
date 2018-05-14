<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
 #license {
	 border: solid;
	 padding: 0 1em;
 }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'License');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>The body of REDUCE itself is subject to the BSD-style license shown below, but some versions of REDUCE rely on various libraries that are subject to the LGPL license or are public domain, the full details of which should be visible in the source tree.</p>
<div id="license">
	<p>Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:</p>
	<ul>
		<li>Redistributions of source code must retain the relevant copyright notice, this list of conditions and the following disclaimer.</li>
		<li>Redistributions in binary form must reproduce the relevant copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.</li>
	</ul>
	<p>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS &quot;AS IS&quot; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</p>
</div>
END_OF_MAIN_CONTENT
);

$smarty->display('secondary.tpl');

?>
