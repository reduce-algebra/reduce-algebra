{* Smarty *}
{extends file="main.tpl"}

{block name=javascript}
<script>
  // Handle REDUCE manual links that need to be looked up for robustness,
  // which have the form <a class="manual-lookup" title="GROEBNER">.
  // First create a hidden manual table of contents:
  $("body").append("<div id='toc' style='display:none'>")
  // Then load all the CHILDREN of the TOC:
  $("#toc").load("/manual/manual.html div.tableofcontents > *",
                 function() {
                     // Once the TOC has loaded,
                     // update the links to be looked up:
                     $("a.manual-lookup").attr("href", function() {
                         return "/manual/" + $("#toc > span > a:contains(" + $(this).attr("title") + ")").attr("href")
                     })
                 })
</script>
{/block}
