<?php

require_once('php/autoloader.php');
$feed = new SimplePie();
$feed->set_feed_url($_SERVER['QUERY_STRING']);
$feed->init();
 
?><!DOCTYPE html>
 
<html>
<head>
	<title></title>
	<style type="text/css">
		body {
			font-family: Arial, Helvetica, sans-serif;
		}

		a:link, a:active, a:visited {
			text-decoration: none;
		}

		a:hover {
			text-decoration: underline;
		}

		h1, h2 {
			font-family: Georgia, Times, 'Times New Roman', serif;
		}

		h1 {
			font-size: 1rem;
			text-align: center;
		}

		h2 {
			font-size: 0.9rem;
			margin: 1em 0 0.5em;
		}

		div.RSSitem {
			font-size: 0.8rem;
		}

		p {
			margin: 0.5em 0;
		}
	</style>
</head>
<body>
 
	<h1><a href="<?= $feed->get_permalink(); ?>"><?= $feed->get_title(); ?></a></h1>
 
	<?php foreach ($feed->get_items() as $item): ?>
 
		<div class="RSSitem">
			<h2><a href="<?= $item->get_permalink(); ?>"><?= $item->get_title(); ?></a></h2>
			<div><?= $item->get_description(); ?></div>
			<p><small>Posted by <?= $item->get_author(0)->get_name(); ?> on <?= $item->get_date('j M Y'); ?></small></p>
		</div>
 
	<?php endforeach; ?>
 
</body>
</html>