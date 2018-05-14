{* Smarty *}
<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
		{block name=title}
			<title>
				{$page_title|default: "REDUCE $header_title"}
			</title>
		{/block}
		<link rel="icon" type="image/png" href="images/icon.png" />
		<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css"
			  integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB" crossorigin="anonymous" />
		{block name=stylesheet}
			<link rel="stylesheet" href="StyleSheet.css" />
		{/block}
		{block name=style}
			{$head_extras|default:''}
		{/block}
	</head>
	<body>
		<div class="container-fluid">
			{block name=header}
				<header><img src="images/icon.png" class="d-none d-md-block" />
					{$header_title}
				</header>
			{/block}
			<div class="row">
				{block name=root}{/block}
				{include file='navigation.tpl'}
				{block name=main}
					<div id="main" class="col-md-9 col-xl-7">
						{$main_content}
					</div>
				{/block}
				{block name=footer}
					{include file='footer.tpl' class='col-xl-3'}
				{/block}
			</div>
		</div>
	</body>
</html>
