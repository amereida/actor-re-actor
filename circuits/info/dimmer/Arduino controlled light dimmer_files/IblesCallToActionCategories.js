Ibles.package("Ibles.views", "Ibles.models");

Ibles.categorySignupTemplate = "";
Ibles.categorySignupTemplate += "<div class=\"category call-to-action << display >> <[ if (display === 'modal') { ]> fade hide <[ } ]>\" data-type=\"type-<< bannerType >>\">";
Ibles.categorySignupTemplate += "    <button type=\"button\" class=\"close alert-close\"><span>x</span><\/button>";
Ibles.categorySignupTemplate += "    <div class=\"call-to-action-<< category >>-robot-img\"><\/div>";
Ibles.categorySignupTemplate += "    <div>";
Ibles.categorySignupTemplate += "		<h1><< message >><\/h1>";
Ibles.categorySignupTemplate += "		<p><< subtitle >><\/p>";
Ibles.categorySignupTemplate += "    <\/div>";
Ibles.categorySignupTemplate += "    <div class=\"call-to-action-form\">";
Ibles.categorySignupTemplate += "    <[ if (linkOnly) { ]>";
Ibles.categorySignupTemplate += "		<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-submit submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.categorySignupTemplate += "    <[ } else { ]>";
Ibles.categorySignupTemplate += "    	<[ if (display !== \"mobile\"){ ]>";
Ibles.categorySignupTemplate += "			<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>";
Ibles.categorySignupTemplate += "			<br\/>";
Ibles.categorySignupTemplate += "			<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-submit submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.categorySignupTemplate += "		<[ } else { ]>";
Ibles.categorySignupTemplate += "			<div class=\"input-group\">";
Ibles.categorySignupTemplate += "				<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>";
Ibles.categorySignupTemplate += "				<span class=\"input-group-addon submit-form btn btn-orange signup-prompt-category-submit\"><< buttonText >><\/span>";
Ibles.categorySignupTemplate += "			<\/div>";
Ibles.categorySignupTemplate += "		<[ } ]>";
Ibles.categorySignupTemplate += "    <[ } ]>";
Ibles.categorySignupTemplate += "";
Ibles.categorySignupTemplate += "    <\/div>";
Ibles.categorySignupTemplate += "    <div class=\"call-to-action-signin\">";
Ibles.categorySignupTemplate += "        <p>Already a member? <a class=\"login-link\" data-sourcea=\"banner\" href=\"/account/login?<<continueParams>>\">Login &raquo;</a></p>";
Ibles.categorySignupTemplate += "    <\/div>";
Ibles.categorySignupTemplate += "<\/div>";


Ibles.mobileCategoryTemplate = "";
Ibles.mobileCategoryTemplate += "<div class=\"category call-to-action fade << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobileCategoryTemplate += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobileCategoryTemplate += "		<div class=\"modal-content\">";
Ibles.mobileCategoryTemplate += "		    <button type=\"button\" class=\"close alert-close\"><span>x</span><\/button>";
Ibles.mobileCategoryTemplate += "			<div class=\"call-to-action-<< category >>-robot-img\"><\/div>";
Ibles.mobileCategoryTemplate += "		    <div>		";
Ibles.mobileCategoryTemplate += "				<h1><< message >><\/h1>		";
Ibles.mobileCategoryTemplate += "				<p><< subtitle >><\/p>    ";
Ibles.mobileCategoryTemplate += "			<\/div>    ";
Ibles.mobileCategoryTemplate += "			<div class=\"call-to-action-form\">    ";
Ibles.mobileCategoryTemplate += "				<[ if (linkOnly) { ]>";
Ibles.mobileCategoryTemplate += "					<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-submit-mobile submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.mobileCategoryTemplate += "				<[ } else { ]>";
Ibles.mobileCategoryTemplate += "					<[ if (display !== \"mobile\"){ ]>";
Ibles.mobileCategoryTemplate += "						<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>			";
Ibles.mobileCategoryTemplate += "						<br\/>			";
Ibles.mobileCategoryTemplate += "						<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-submit-mobile submit-form btn btn-orange\"><< buttonText >><\/a>		";
Ibles.mobileCategoryTemplate += "					<[ } else { ]>			";
Ibles.mobileCategoryTemplate += "						<div class=\"input-group\">				";
Ibles.mobileCategoryTemplate += "							<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>				";
Ibles.mobileCategoryTemplate += "							<span class=\"input-group-addon submit-form btn btn-orange signup-prompt-category-submit-mobile\"><< buttonText >><\/span>			";
Ibles.mobileCategoryTemplate += "						<\/div>		";
Ibles.mobileCategoryTemplate += "					<[ } ]>    ";
Ibles.mobileCategoryTemplate += "				<[ } ]>    ";
Ibles.mobileCategoryTemplate += "			<\/div>    ";
Ibles.mobileCategoryTemplate += "           <div class=\"call-to-action-signin\">";
Ibles.mobileCategoryTemplate += "               <p>Already a member? <a class=\"login-link\" data-sourcea=\"banner\" href=\"<< loginSignupProtocol >><< host >>/account/login?<<continueParams>>\">Login &raquo;</a></p>";
Ibles.mobileCategoryTemplate += "           <\/div>";
Ibles.mobileCategoryTemplate += "		<\/div>";
Ibles.mobileCategoryTemplate += "	<\/div>";
Ibles.mobileCategoryTemplate += "<\/div>";

Ibles.mobileCategoryBanner="";
Ibles.mobileCategoryBanner += "<div class=\"category call-to-action banner banner-link << display >>\">";
Ibles.mobileCategoryBanner += "	<button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>&times;<\/span><\/button>";
Ibles.mobileCategoryBanner += "	<div class=\"message\">";
Ibles.mobileCategoryBanner += "   <a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\">";
Ibles.mobileCategoryBanner += "		<div class=\"call-to-action-<< category >>-robot-img\"><\/div>";
Ibles.mobileCategoryBanner += "   </a>";
Ibles.mobileCategoryBanner += "	    <div class=\"title\">";
Ibles.mobileCategoryBanner += "         << message >>";
Ibles.mobileCategoryBanner += "	    <\/div>";
Ibles.mobileCategoryBanner += "		<div class=\"message-text\">";
Ibles.mobileCategoryBanner += "         <a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-link-mobile\">Sign Up for Free &raquo;<\/a>";
Ibles.mobileCategoryBanner += "		<\/div>";
Ibles.mobileCategoryBanner += "	<\/div>";
Ibles.mobileCategoryBanner += "<\/div>";

Ibles.mobileCategoryBannerBtn="";
Ibles.mobileCategoryBannerBtn += "<div class=\"category call-to-action banner banner-btn << display >>\">";
Ibles.mobileCategoryBannerBtn += "	<button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>&times;<\/span><\/button>";
Ibles.mobileCategoryBannerBtn += "	<div class=\"message\">";
Ibles.mobileCategoryBannerBtn += "    <a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" >";
Ibles.mobileCategoryBannerBtn += "		<div class=\"call-to-action-<< category >>-robot-img\"><\/div>";
Ibles.mobileCategoryBannerBtn += "    </a>";
Ibles.mobileCategoryBannerBtn += "	    <div class=\"title\">";
Ibles.mobileCategoryBannerBtn += "         << message >>";
Ibles.mobileCategoryBannerBtn += "	    <\/div>";
Ibles.mobileCategoryBannerBtn += "		<div class=\"message-text\">";
Ibles.mobileCategoryBannerBtn += "         <a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-btn-mobile btn btn-lg btn-orange\">Sign Me Up! &raquo;<\/a>";
Ibles.mobileCategoryBannerBtn += "		<\/div>";
Ibles.mobileCategoryBannerBtn += "	<\/div>";
Ibles.mobileCategoryBannerBtn += "<\/div>";

Ibles.mobileCategoryBannerForm="";
Ibles.mobileCategoryBannerForm += "<div class=\"category call-to-action banner banner-form << display >>\">";
Ibles.mobileCategoryBannerForm += "	<button type=\"button\" class=\"close light alert-close\" data-dismiss=\"modal\"><span>&times;<\/span><\/button>";
Ibles.mobileCategoryBannerForm += "	<div class=\"message\">";
Ibles.mobileCategoryBannerForm += "   <div>";
Ibles.mobileCategoryBannerForm += "		<div class=\"call-to-action-<< category >>-robot-img\"><\/div>";
Ibles.mobileCategoryBannerForm += "	    <div class=\"title\">";
Ibles.mobileCategoryBannerForm += "         << message >>";
Ibles.mobileCategoryBannerForm += "	    <\/div>";
Ibles.mobileCategoryBannerForm += "	  <\/div>";
Ibles.mobileCategoryBannerForm += "		<div class=\"call-to-action-form\">";
Ibles.mobileCategoryBannerForm += "		<input type=\"email\" data-error-msg=\"Please enter a valid email\" class=\"signup-prompt-email input-large form-control\" placeholder=\"Your email...\"\/>			";
Ibles.mobileCategoryBannerForm += "		<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-category-submit-mobile submit-form btn btn-lg btn-orange\">Sign Up! &raquo;<\/a>		";
Ibles.mobileCategoryBannerForm += "		<\/div>";
Ibles.mobileCategoryBannerForm += "	<\/div>";
Ibles.mobileCategoryBannerForm += "<\/div>";

Ibles.views.CallToActionView = Backbone.View.extend({
    events: {
        "click .submit-form":"submitForm",
        "click .close": "close",
        "click .login-link": "close",
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
        if (this.model.get('display').indexOf('modal') !== -1  && $('.modal.in:visible').length === 0){
            this.$('.call-to-action').modal('show');
        } else {
            this.$('.call-to-action').fadeIn(200);
        }
    },
    submitForm: function(){
    },
    setClosedCookie:function(){

    },

    render: function(){
        this.$el.html(this.template(this.model.toJSON()));
        head.load("https://cdn.instructables.com/static/gtm/css/call_to_action_beta.css");
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

Ibles.views.CategorySignupPromptView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.categorySignupTemplate),
    initialize: function(){
        if (this.model.get('display') === 'mobile modal'){
            //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
            this.template = _.template(Ibles.mobileCategoryTemplate);
        }
        this.render();
    },
    submitForm: function(e){
        e.preventDefault();
        var that = this;
        var email = this.$el.find('.signup-prompt-email').val() || "",
            bannerType = this.model.get('bannerType'),
            sourceaUrl = encodeURIComponent(window.location.pathname + window.location.search),
            protocol = this.model.get('loginSignupProtocol');

        if (email) {
            $.ajax({
                url: protocol + window.location.host + "/newsletter/newslettersignup?email="+encodeURIComponent(email),
                method: "GET",
                success: function() {
                    window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&bannerType="+bannerType+"&email="+encodeURIComponent(email);
                }
            });
        } else {

            window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&bannerType="+ bannerType;
        }
    },
    setClosedCookie: function(){
        // show banner once every 30 minutes
        var date = new Date();
        var minutes = 30;
        date.setTime(date.getTime() + (minutes * 60 * 1000));

        $.cookie('SignupPromptClosedBefore', 'true', {path: '/', expires: date});
    }
});

Ibles.views.CategorySignupBannerView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.mobileCategoryBanner),
    initialize: function(){
        this.render();
    },
    setClosedCookie: function(){
        // show banner once every 30 minutes
        var date = new Date();
        var minutes = 30;
        date.setTime(date.getTime() + (minutes * 60 * 1000));
        $.cookie('SignupPromptClosedBefore', 'true', {path: '/', expires: date});
    }
});

Ibles.views.CategorySignupBannerBtnView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.mobileCategoryBannerBtn),
    initialize: function(){
        this.render();
    },
    setClosedCookie: function(){
        // show banner once every 30 minutes
        var date = new Date();
        var minutes = 30;
        date.setTime(date.getTime() + (minutes * 60 * 1000));
        $.cookie('SignupPromptClosedBefore', 'true', {path: '/', expires: date});
    }
});

Ibles.views.CategorySignupBannerFormView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.mobileCategoryBannerForm),
    initialize: function(){
        this.render();
    },
    submitForm: function(e){
        e.preventDefault();
        var that = this;
        var email = this.$el.find('.signup-prompt-email').val() || "",
            bannerType = this.model.get('bannerType'),
            sourceaUrl = encodeURIComponent(window.location.pathname + window.location.search),
            protocol = this.model.get('loginSignupProtocol');

        var isEmail = function(email) {
            var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
            return regex.test(email);
        };

        if (email && isEmail(email)) {
            $.ajax({
                url: protocol + window.location.host + "/newsletter/newslettersignup?email="+encodeURIComponent(email),
                method: "GET",
                success: function() {
                    window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&bannerType="+bannerType+"&email="+encodeURIComponent(email);
                }
            });
        } else {

            this.$el.find('.signup-prompt-email').tooltip({
                title: this.$el.find('.signup-prompt-email').data('error-msg'),
                trigger: "manual"
            }).on('show', function(e){
                    e.stopPropagation();
                }).on('hidden', function(e){
                    e.stopPropagation();
                });
            this.$el.find('.signup-prompt-email').tooltip('show');
            this.$el.find('.signup-prompt-email').next('.tooltip').css({left: 0, top:'47px'});
            this.$el.find('.signup-prompt-email').next('.tooltip').find('.tooltip-inner').css({padding:'0 10px', backgroundColor:'#BD362F'});
            this.$el.find('.signup-prompt-email').next('.tooltip').find('.tooltip-arrow').hide();
            this.$el.find('.signup-prompt-email').css({border:'1px solid #BD362F'});
            window.setTimeout(function() {
                this.$el.find('.signup-prompt-email').tooltip('hide').tooltip('destroy');
            }, 3000);

        }
    },
    setClosedCookie: function(){
        // show banner once every 30 minutes
        var date = new Date();
        var minutes = 30;
        date.setTime(date.getTime() + (minutes * 60 * 1000));

        $.cookie('SignupPromptClosedBefore', 'true', {path: '/', expires: date});
    }
});

Ibles.showCategorySignupPrompt = function(model, delay) {
    var signup_model = new Ibles.models.CallToAction(model)
    var signup_prompt = new Ibles.views.CategorySignupPromptView({model:signup_model});
    $("body").append(signup_prompt.$el);
    setTimeout(function(){
        signup_prompt.show();
    }, delay);
};

Ibles.showMobileCategorySignupBanner = function(model, delay) {
    var signup_model = new Ibles.models.CallToAction(model)
    var signup_prompt = new Ibles.views.CategorySignupBannerView({model:signup_model});
    $("body").append(signup_prompt.$el);
    setTimeout(function(){
        signup_prompt.show();
    }, delay);
};

Ibles.showMobileCategorySignupBannerBtn = function(model, delay) {
    var signup_model = new Ibles.models.CallToAction(model)
    var signup_prompt = new Ibles.views.CategorySignupBannerBtnView({model:signup_model});
    $("body").append(signup_prompt.$el);
    setTimeout(function(){
        signup_prompt.show();
    }, delay);
};

Ibles.showMobileCategorySignupBannerForm = function(model, delay) {
    var signup_model = new Ibles.models.CallToAction(model)
    var signup_prompt = new Ibles.views.CategorySignupBannerFormView({model:signup_model});
    $("body").append(signup_prompt.$el);
    setTimeout(function(){
        signup_prompt.show();
    }, delay);
};

