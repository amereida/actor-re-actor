Ibles.package("Ibles.views", "Ibles.models");

Ibles.classPromoTemplate = "";
Ibles.classPromoTemplate += "<div class=\"category class-cta call-to-action desktop << imgClass >> << display >> hide fade\" data-type=\"type-<< bannerType >>\">";
Ibles.classPromoTemplate += "    <button type=\"button\" class=\"close light alert-close\"><span>x</span><\/button>";
Ibles.classPromoTemplate += "   <a href=\"<< classUrl >>\" class=\"cta-class-link btn btn-orange btn-large\"> << buttonText >>";
Ibles.classPromoTemplate += "		</a>";
Ibles.classPromoTemplate += "<\/div>";

Ibles.mobileClassPromoTemplate = "";
Ibles.mobileClassPromoTemplate += "<div class=\"category call-to-action class-cta << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobileClassPromoTemplate += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobileClassPromoTemplate += "		<div class=\"modal-content\">";
Ibles.mobileClassPromoTemplate += "		    <button type=\"button\" data-dismiss=\"modal\" class=\"close light alert-close\"><span>x</span><\/button>";
Ibles.mobileClassPromoTemplate += "		    <div class=\"class-cta-image << imgClass>> \">		</div>";
Ibles.mobileClassPromoTemplate += "		    <div class=\"call-to-action-message\">		";
Ibles.mobileClassPromoTemplate += "				<h1>Like << classTitle >>? <br/> We have a free class for that!<\/h1>		";
Ibles.mobileClassPromoTemplate += "				<p><< message >><\/p>    ";
Ibles.mobileClassPromoTemplate += "			<\/div>";
Ibles.mobileClassPromoTemplate += "			<div class=\"call-to-action-form\">    ";
Ibles.mobileClassPromoTemplate += "			    <a href=\"<< classUrl >>\" class=\"btn btn-lg btn-orange cta-class-link\"><< buttonText >><\/a>";
Ibles.mobileClassPromoTemplate += "			<\/div>    ";
Ibles.mobileClassPromoTemplate += "		<\/div>";
Ibles.mobileClassPromoTemplate += "	<\/div>";
Ibles.mobileClassPromoTemplate += "<\/div>";


Ibles.classGoPremiumTemplate = "";
Ibles.classGoPremiumTemplate += "<div class=\"class-premium-prompt call-to-action << display >> hide\" data-type=\"type-<< bannerType >>\">";
Ibles.classGoPremiumTemplate += "    <button type=\"button\" data-dismiss=\"modal\" class=\"close light alert-close\"><span>x</span><\/button>";
Ibles.classGoPremiumTemplate += "    <div class=\"call-to-action-message\">";
Ibles.classGoPremiumTemplate += "		<div class=\"class-premium-prompt-image \">		</div>";
Ibles.classGoPremiumTemplate += "		<h1>We're thrilled to announce the launch of our online classes!<\/h1>    ";
Ibles.classGoPremiumTemplate += "		<p><< message >><\/p>";
Ibles.classGoPremiumTemplate += "    <\/div>";
Ibles.classGoPremiumTemplate += "    <div class=\"call-to-action-btn\">";
Ibles.classGoPremiumTemplate += "		<a href=\"<< loginSignupProtocol >><< host >><< premiumLink >>\" class=\"btn btn-large btn-orange class-premium-link\"><< buttonText >><\/a>";
Ibles.classGoPremiumTemplate += "    <\/div>";
Ibles.classGoPremiumTemplate += "<\/div>";


Ibles.mobileClassGoPremiumTemplate = "";
Ibles.mobileClassGoPremiumTemplate += "<div class=\"class-premium-prompt call-to-action << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobileClassGoPremiumTemplate += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobileClassGoPremiumTemplate += "		<div class=\"modal-content\">";
Ibles.mobileClassGoPremiumTemplate += "		    <button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>x</span><\/button>";
Ibles.mobileClassGoPremiumTemplate += "		    <div class=\"call-to-action-message\">		";
Ibles.mobileClassGoPremiumTemplate += "		        <div class=\"class-premium-prompt-image \">		</div>";
Ibles.mobileClassGoPremiumTemplate += "				<h4>We're thrilled to announce the launch of our online classes!<\/h4>    ";
Ibles.mobileClassGoPremiumTemplate += "				<p><< message >><\/p>    ";
Ibles.mobileClassGoPremiumTemplate += "			<\/div>";
Ibles.mobileClassGoPremiumTemplate += "			<div class=\"call-to-action-form\">    ";
Ibles.mobileClassGoPremiumTemplate += "			    <a href=\"<< loginSignupProtocol >><< host >><< premiumLink >>\" class=\"btn btn-orange class-premium-link\"><< buttonText >><\/a>";
Ibles.mobileClassGoPremiumTemplate += "			<\/div>    ";
Ibles.mobileClassGoPremiumTemplate += "		<\/div>";
Ibles.mobileClassGoPremiumTemplate += "	<\/div>";
Ibles.mobileClassGoPremiumTemplate += "<\/div>";


Ibles.mobileClassesCTA = "";
Ibles.mobileClassesCTA += "<div class=\"class-premium-prompt call-to-action << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobileClassesCTA += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobileClassesCTA += "		<div class=\"modal-content\">";
Ibles.mobileClassesCTA += "		    <button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>x</span><\/button>";
Ibles.mobileClassesCTA += "		    <div class=\"call-to-action-message\">		";
Ibles.mobileClassesCTA += "             <a href=\"<< loginSignupProtocol >><< host >>\/classes?sourcea=banner&bannerType=<< bannerType >>\">";
Ibles.mobileClassesCTA += "		        <div class=\"class-graduation-robot-image\">		</div>";
Ibles.mobileClassesCTA += "             </a>";
Ibles.mobileClassesCTA += "				<p><< message >><\/p>    ";
Ibles.mobileClassesCTA += "			    <div class=\"call-to-action-form\">    ";
Ibles.mobileClassesCTA += "                   <a href=\"<< loginSignupProtocol >><< host >>\/classes?sourcea=banner&bannerType=<< bannerType >>\" class=\"btn btn-lg btn-orange cta-class-link\"><< buttonText >><\/a>";
Ibles.mobileClassesCTA += "			    <\/div>    ";
Ibles.mobileClassesCTA += "			<\/div>";
Ibles.mobileClassesCTA += "		<\/div>";
Ibles.mobileClassesCTA += "	<\/div>";
Ibles.mobileClassesCTA += "<\/div>";

Ibles.mobileClassBanner="";
Ibles.mobileClassBanner += "<div class=\"call-to-action << display >>\">";
Ibles.mobileClassBanner += "	<button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>&times;<\/span><\/button>";
Ibles.mobileClassBanner += "	<div class=\"message\">";
Ibles.mobileClassBanner += "		<div class=\"class-image << imgClass >>\">";
Ibles.mobileClassBanner += "		<\/div>";
Ibles.mobileClassBanner += "		<div class=\"title\">";
Ibles.mobileClassBanner += "            << message >>";
Ibles.mobileClassBanner += "		<\/div>";
Ibles.mobileClassBanner += "	<\/div>";
Ibles.mobileClassBanner += "<\/div>";

Ibles.views.CallToActionView = Backbone.View.extend({
    events: {
        "click .close": "close",
        "click .class-link": "close",
        "click .overlay-open":"show"
    },
    close: function(){
        var that = this;
        if (this.model.get('display').indexOf('modal') !== -1 ){
            this.$('.call-to-action').modal('hide');

        } else {
            this.$('.call-to-action').fadeOut(200);
        }
        this.setClosedCookie();

    },
    show: function(){
        if (this.model.get('display').indexOf('modal') !== -1){
			if ($('.modal.in:visible').length === 0){
	            this.$('.call-to-action').modal('show');
			}
        } else {
            this.$('.call-to-action').fadeIn(200);
        }
    },
    setClosedCookie:function(){
        // show banner once every day
        var date = new Date();
        date.setTime(date.getTime() + (60 * 24 * 60 * 1000));
        $.cookie('ClassPromoPromptClosedBefore', 'true', {path: '/', expires: date});
    },

    render: function(){
        this.$el.html(this.template(this.model.toJSON()));
        head.load("https://cdn.instructables.com/static/gtm/css/call_to_action.css");
        return this.el;
    }
});

Ibles.models.CallToAction = Backbone.Model.extend({
    defaults:{
        bannerType:"",
        message:"",
        subtitle:"",
        display:"",
        buttonText:"",
        linkOnly:false,
        category: "",
        loginSignupProtocol:"http://",
        host: window.location.host
    }
});

Ibles.views.ClassPromptView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.classPromoTemplate),
    initialize: function(){
        if (this.model.get('display') === 'mobile modal'){
            //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
            this.template = _.template(Ibles.mobileClassPromoTemplate);
        } else if (this.model.get('display').indexOf('mobile banner') > -1) {
            this.template = _.template(Ibles.mobileClassBanner);
        }
        this.render();
    }
});


Ibles.views.ClassPremiumPromptView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.classGoPremiumTemplate),
    initialize: function(){
        if (this.model.get('display') === 'mobile modal'){
            //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
            this.template = _.template(Ibles.mobileClassGoPremiumTemplate);
        }
        this.render();
    },
    setClosedCookie: function(){
        // show prompt once day
        $.cookie('PremiumPromptClosedBefore', 'true', {path: '/', expires: 1});
    }
});


Ibles.views.ClassBannerCTA = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.mobileClassesCTA),
    initialize: function(){
        this.render();
    },
    setClosedCookie: function(){
        // show prompt once day
        $.cookie('PremiumPromptClosedBefore', 'true', {path: '/', expires: 1});
    }
});

Ibles.showClassPromoPrompt = function(model, delay) {
    var promo_model = new Ibles.models.CallToAction(model);
    var promo_prompt = new Ibles.views.ClassPromptView({model:promo_model});
    $("body").append(promo_prompt.$el);
    setTimeout(function(){
        promo_prompt.show();
    }, delay);
};

Ibles.showClassGoPremiumPrompt = function(model, delay) {
    var promo_model = new Ibles.models.CallToAction(model);
    var promo_prompt = new Ibles.views.ClassPremiumPromptView({model:promo_model});
    $("body").append(promo_prompt.$el);
    setTimeout(function(){
        promo_prompt.show();
    }, delay);
};

Ibles.showClassCTA = function(model, delay) {
    var promo_model = new Ibles.models.CallToAction(model);
    var promo_prompt = new Ibles.views.ClassBannerCTA({model:promo_model});
    $("body").append(promo_prompt.$el);
    setTimeout(function(){
        promo_prompt.show();
    }, delay);
};