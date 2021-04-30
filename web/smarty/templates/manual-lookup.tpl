{* Smarty *}
{extends file="main.tpl"}

{block name=javascript}
<script>
  // Non-interactive use:
  queryString = location.search;
  if (queryString.length > 0) {
      queryString = decodeURIComponent(queryString.substring(1));
      processQueryString(queryString);
  }

  function processQueryString(queryString) {
      // alert(queryString);
      // First create a hidden manual table of contents:
      $("body").append("<div id='toc' style='display:none'>")
      // Then load all the CHILDREN of the TOC:
      $("#toc").load("/manual/manual.html div.tableofcontents > *",
		     function () {
			 // Once the TOC has loaded, look up the link:
			 tocAnchor = $("#toc > span > a:contains(" + queryString + ")");
			 // This is an array-like object, so...
			 if (tocAnchor.length == 0)
			     // Search string not found.
			     filename = "manual.html";
			 else
			     filename = tocAnchor.attr("href");
			 location.replace("/manual/" + filename)
		     })
  }

  // Interactive use:
  $("span.href").append(location.href);

  $("#Button1").click(Go);

  $("body").keypress(
      function (event) {
	  if (event.keyCode == 13) Go();
      })

  function Go() {
      queryString = $("#Text1").val();
      if (queryString.length > 0) {
	  processQueryString(queryString);
      }
  }
</script>
{/block}
