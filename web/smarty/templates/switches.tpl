{* Smarty *}
{extends file="main.tpl"}
{block name=header}
	<h1>
		{$header_title}
	</h1>
{/block}

{block name=main}
	{$preambleA}
	<table class="table">
		<thead>
			<tr>
				<th scope="col">Switch</th>
				<th scope="col">Default</th>
				<th scope="col">Controls</th>
				<th scope="col">Effect</th>
			</tr>
		</thead>
		<tbody>
			{foreach $switchesA as $switchrow}
				<tr>
					<th scope="row">{$switchrow.0}</th>
					<td>{$switchrow.1}</td>
					<td>{$switchrow.2}</td>
					<td>{$switchrow.3}</td>
				</tr>
			{/foreach}
		</tbody>
	</table>

	{$preambleB}
	<table class="table">
		<thead>
			<tr>
				<th scope="col">Switch</th>
				<th scope="col">Default</th>
				<th scope="col">Controls</th>
				<th scope="col">Effect</th>
			</tr>
		</thead>
		<tbody>
			{foreach $switchesB as $switchrow}
				<tr>
					<th scope="row">{$switchrow.0}</th>
					<td>{$switchrow.1}</td>
					<td>{$switchrow.2}</td>
					<td>{$switchrow.3}</td>
				</tr>
			{/foreach}
		</tbody>
	</table>
{/block}
