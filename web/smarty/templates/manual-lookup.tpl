{* Smarty *}
{extends file="main.tpl"}

{block name=javascript}
<script>
  // $("span.href").append(location.href);
  $("span.href").append(location.origin + location.pathname);
  $("#Button1").click(Go);
  $("body").keypress(
      function (event) {
	  if (event.keyCode == 13) Go();
      });

  function Go() {
      var queryString = $("#Text1").val();
      if (queryString.length > 0)
	  location.replace(location.origin + location.pathname
                           + "?" + queryString);
  }
</script>
{/block}
