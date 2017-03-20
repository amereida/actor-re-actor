$(document).ready(function() {
	var img = new Image(1, 1);
	img.src = config.ShopPath + '/index.php?action=track_visitor&' + new Date().getTime();
	img.onload = function() { return true; };
});
