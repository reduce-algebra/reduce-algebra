{* Smarty *}
{extends file="main.tpl"}

{block name=style}
<style type="text/css">
  #contrib > span.chapterToc > a {
      font-size: x-large;
  }
</style>

<base href="/manual/" />
{/block}

{block name=main}
{$main_content}
<div id="contrib">
  <p>A list of user-contributed packages is being generated...</p>
</div>
{/block}

{block name=javascript}
<script>
  $("#contrib").
    load("/manual/manual.html div.tableofcontents > *",
         function() {  // invoked once as a method of each element of the jQuery object
             $("#contrib > span.chapterToc:has(a:contains(User Contributed Packages))").prevAll().remove()
             $("#contrib > span.chapterToc:nth(1)").nextAll().addBack().remove()
             // Remove numbering from heading:
             $("#contrib > span.chapterToc").contents().first().remove()
             $("#contrib > span.sectionToc").each(function() {
                 var $this = $(this)
                 // Replace numbering of package with space:
                 $this.contents().first().replaceWith("&emsp;&emsp;")
                 // Embolden the package name (before colon):
                 $this.find("a").html(function(n, current){
                     var ind = current.search(":");
                     return "<b>" + current.substring(0, ind) + "</b>" + current.substring(ind)
                 })
             })
         })
</script>
{/block}
