/*
FWB SLIDER JQUERY
*/

(function($){
    $.fwbslider = function(selector, settings){
        // settings
        var config = {
            'delay': 2000,
            'fadeSpeed': 500
        };
        if ( settings ){$.extend(config, settings);}
        // variables
        var obj = $(selector);
        var slide = obj.find('img');
        var count = slide.length;
        var i = 0;
 
        // show first slide
        slide.eq(0).show();
 
		if(count!=1){
        // run slideshow
        setInterval(function(){
            slide.eq(i).fadeOut(config.fadeSpeed);
            i = ( i+1 == count ) ? 0 : i+1;
            slide.eq(i).fadeIn(config.fadeSpeed);
        }, config.delay);
		}
 
        return this;
    };
})(jQuery);
