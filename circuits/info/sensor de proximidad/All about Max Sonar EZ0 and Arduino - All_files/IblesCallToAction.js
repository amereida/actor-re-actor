Ibles.package("Ibles.views", "Ibles.models");

Ibles.signupBannerTemplate = "";
Ibles.signupBannerTemplate += "<div class=\"<< display>> overlay-open\">";
Ibles.signupBannerTemplate += "	<img src=\"\/static\/img\/header\/header-robot.png\"\/>";
Ibles.signupBannerTemplate += "	<p class=\"overlay-message\"> Join Us! <\/p>";
Ibles.signupBannerTemplate += "<\/div>";
Ibles.signupBannerTemplate += "<div class=\"call-to-action << display >> <[ if (display === 'modal') { ]> hide fade <[ } ]>\" data-type=\"type-<< bannerType >>\">";
Ibles.signupBannerTemplate += "    <button type=\"button\" data-dismiss=\"modal\" class=\"close alert-close\"><span>x<\/span><\/button>";
Ibles.signupBannerTemplate += "    <div>";
Ibles.signupBannerTemplate += "		<h1><< message >><\/h1>";
Ibles.signupBannerTemplate += "		<p><< subtitle >><\/p>";
Ibles.signupBannerTemplate += "    <\/div>";
Ibles.signupBannerTemplate += "    <div class=\"call-to-action-form\">";
Ibles.signupBannerTemplate += "    <[ if (linkOnly) { ]>";
Ibles.signupBannerTemplate += "		<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>&utm_medium=cta&tum_source=popup&utm_campaign=signup\" class=\"signup-prompt-submit submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.signupBannerTemplate += "    <[ } else { ]>";
Ibles.signupBannerTemplate += "    	<[ if (display !== \"mobile\"){ ]>";
Ibles.signupBannerTemplate += "			<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>";
Ibles.signupBannerTemplate += "			<br\/>";
Ibles.signupBannerTemplate += "			<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-submit submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.signupBannerTemplate += "		<[ } else { ]>";
Ibles.signupBannerTemplate += "			<div class=\"input-group\">";
Ibles.signupBannerTemplate += "				<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>";
Ibles.signupBannerTemplate += "				<span class=\"input-group-addon submit-form btn btn-orange signup-prompt-submit\"><< buttonText >><\/span>";
Ibles.signupBannerTemplate += "			<\/div>";
Ibles.signupBannerTemplate += "		<[ } ]>";
Ibles.signupBannerTemplate += "    <[ } ]>";
Ibles.signupBannerTemplate += "";
Ibles.signupBannerTemplate += "    <\/div>";
Ibles.signupBannerTemplate += "    <div class=\"call-to-action-robot-img\"><\/div>";
Ibles.signupBannerTemplate += "<\/div>";

Ibles.premiumPromptTemplate="";
Ibles.premiumPromptTemplate += "    <div class=\"call-to-action << display >> premium-prompt\" data-type=\"type-<< bannerType >>\" style=\"display:block\">";
Ibles.premiumPromptTemplate += "        <button type=\"button\" data-dismiss=\"modal\" class=\"close alert-close\"><span>x</span><\/button>";
Ibles.premiumPromptTemplate += "        <div class=\"call-to-action-header\"><\/div>";
Ibles.premiumPromptTemplate += "        <div class=\"call-to-action-form\">";
Ibles.premiumPromptTemplate += "            <p><< message >><\/p>";
Ibles.premiumPromptTemplate += "            <a href=\"https:\/\/ssl.instructables.com\/payment\/pay\/?paymentPlan=TWO_YEAR_SINGLE_PAYMENT&sourcea=cta&utm_medium=cta&tum_source=popup&utm_campaign=supportdiy\" class=\"submit-form btn btn-orange premium-signup-link\"><< buttonText >><\/a>";
Ibles.premiumPromptTemplate += "        <\/div>";
Ibles.premiumPromptTemplate += "    <\/div>";

Ibles.mobilePremiumPromptTemplate="";
Ibles.mobilePremiumPromptTemplate += "<div class=\"call-to-action fade premium-prompt << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobilePremiumPromptTemplate += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobilePremiumPromptTemplate += "		<div class=\"modal-content\">";
Ibles.mobilePremiumPromptTemplate += "        <button type=\"button\" data-dismiss=\"modal\" class=\"close alert-close\"><span>x</span><\/button>";
Ibles.mobilePremiumPromptTemplate += "        <div class=\"call-to-action-header\"><\/div>";
Ibles.mobilePremiumPromptTemplate += "        <div class=\"call-to-action-form\">";
Ibles.mobilePremiumPromptTemplate += "            <p><< message >><\/p>";
Ibles.mobilePremiumPromptTemplate += "            <a href=\"https:\/\/ssl.instructables.com\/payment\/pay\/?paymentPlan=TWO_YEAR_SINGLE_PAYMENT&sourcea=cta&utm_medium=cta&tum_source=popup&utm_campaign=supportdiy\" class=\"submit-form btn btn-orange premium-signup-link\"><< buttonText >><\/a>";
Ibles.mobilePremiumPromptTemplate += "        <\/div>";
Ibles.mobilePremiumPromptTemplate += "		<\/div>";
Ibles.mobilePremiumPromptTemplate += "	<\/div>";
Ibles.mobilePremiumPromptTemplate += "<\/div>";

Ibles.mobileTemplate="";
Ibles.mobileTemplate += "<div class=\"call-to-action hide fade << display >>\" data-type=\"type-<< bannerType >>\">";
Ibles.mobileTemplate += "	<div class=\"modal-dialog modal-sm\">";
Ibles.mobileTemplate += "		<div class=\"modal-content\">";
Ibles.mobileTemplate += "		    <button type=\"button\" data-dismiss=\"modal\" class=\"close alert-close\"><span>x<\/span><\/button>";
Ibles.mobileTemplate += "		    <div>		";
Ibles.mobileTemplate += "				<h1><< message >><\/h1>		";
Ibles.mobileTemplate += "				<p><< subtitle >><\/p>    ";
Ibles.mobileTemplate += "			<\/div>    ";
Ibles.mobileTemplate += "			<div class=\"call-to-action-form\">    ";
Ibles.mobileTemplate += "				<[ if (linkOnly) { ]>";
Ibles.mobileTemplate += "					<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>&utm_medium=cta&tum_source=popup&utm_campaign=signup\" class=\"signup-prompt-submit submit-form btn btn-orange\"><< buttonText >><\/a>";
Ibles.mobileTemplate += "				<[ } else { ]>";
Ibles.mobileTemplate += "					<[ if (display !== \"mobile\"){ ]>";
Ibles.mobileTemplate += "						<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>			";
Ibles.mobileTemplate += "						<br\/>			";
Ibles.mobileTemplate += "						<a href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=banner&bannerType=<< bannerType >>\" class=\"signup-prompt-submit submit-form btn btn-orange\"><< buttonText >><\/a>		";
Ibles.mobileTemplate += "					<[ } else { ]>			";
Ibles.mobileTemplate += "						<div class=\"input-group\">				";
Ibles.mobileTemplate += "							<input type=\"email\" class=\"signup-prompt-email form-control\" placeholder=\"Enter email\"\/>				";
Ibles.mobileTemplate += "							<span class=\"input-group-addon submit-form btn btn-orange signup-prompt-submit\"><< buttonText >><\/span>			";
Ibles.mobileTemplate += "						<\/div>		";
Ibles.mobileTemplate += "					<[ } ]>    ";
Ibles.mobileTemplate += "				<[ } ]>    ";
Ibles.mobileTemplate += "			<\/div>    ";
Ibles.mobileTemplate += "			<div class=\"call-to-action-robot-img\"><\/div>";
Ibles.mobileTemplate += "		<\/div>";
Ibles.mobileTemplate += "	<\/div>";
Ibles.mobileTemplate += "<\/div>";

Ibles.footerPromptTemplate = "";
Ibles.footerPromptTemplate += "<div class=\"call-to-action-footer << display >> fixed-footer\" data-type=\"type-<< bannerType >>\">";
Ibles.footerPromptTemplate += " <div class=\"fixed-wrap\">";
Ibles.footerPromptTemplate += "     <span><< message >></span>";
Ibles.footerPromptTemplate += "     <a href=\"<< linkUrl >>\" ><< linkText >></a>";
Ibles.footerPromptTemplate += "     <button type=\"button\" class=\"close\"><span>&times;<\/span><\/button>";
Ibles.footerPromptTemplate += " <\/div>";
Ibles.footerPromptTemplate += "<\/div>";

Ibles.signupPromptTemplate = "";
Ibles.signupPromptTemplate += "<div class=\"auth-module modal auth-modal auth-prompt hide fade\">";
Ibles.signupPromptTemplate += "    <div class=\"modal-header\">";
Ibles.signupPromptTemplate += "         <button type=\"button\" class=\"close alert-close\" data-dismiss=\"modal\">x</button>";
Ibles.signupPromptTemplate += "         <h3 class=\"center\">login or signup</h3>";
Ibles.signupPromptTemplate += "    </div>";
Ibles.signupPromptTemplate += "    <div class=\"modal-body\">";
Ibles.signupPromptTemplate += "         <form class=\"email-form\" method=\"post\">";
Ibles.signupPromptTemplate += "             <div class=\"field-with-btn\">";
Ibles.signupPromptTemplate += "                 <input type=\"text\" class=\"form-control email-field\" placeholder=\"Email...\">";
Ibles.signupPromptTemplate += "                 <button type=\"submit\" class=\"btn btn-orange submit-btn\">Sign Up &raquo;</button>";
Ibles.signupPromptTemplate += "             </div>";
Ibles.signupPromptTemplate += "         </form>";
Ibles.signupPromptTemplate += "         <p class=\"login-footer\">Already a member? <a class=\"login-link\" href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=emailPrompt\">Login &raquo;</a></p>";
Ibles.signupPromptTemplate += "    </div>";
Ibles.signupPromptTemplate += "</div>";

Ibles.mobileSignupPromptTemplate = "";
Ibles.mobileSignupPromptTemplate += "<div class=\"modal auth-module-mobile auth-modal-mobile auth-prompt fade\">";
Ibles.mobileSignupPromptTemplate += "   <div class=\"modal-dialog modal-sm\">";
Ibles.mobileSignupPromptTemplate += "       <div class=\"modal-content\">";
Ibles.mobileSignupPromptTemplate += "           <div class=\"modal-header\">";
Ibles.mobileSignupPromptTemplate += "               <button type=\"button\" class=\"close alert-close\" data-dismiss=\"modal\">x</button>";
Ibles.mobileSignupPromptTemplate += "               <h4>login or signup</h4>";
Ibles.mobileSignupPromptTemplate += "           </div>";
Ibles.mobileSignupPromptTemplate += "           <div class=\"modal-body\">";
Ibles.mobileSignupPromptTemplate += "               <form class=\"email-form\" method=\"post\">";
Ibles.mobileSignupPromptTemplate += "                   <div class=\"field-with-btn\">";
Ibles.mobileSignupPromptTemplate += "                       <input type=\"email\" class=\"form-control email-field\" placeholder=\"Email...\">";
Ibles.mobileSignupPromptTemplate += "                       <button type=\"submit\" class=\"btn btn-orange submit-btn\">Sign Up &raquo;</button>";
Ibles.mobileSignupPromptTemplate += "                   </div>";
Ibles.mobileSignupPromptTemplate += "               </form>";
Ibles.mobileSignupPromptTemplate += "               <p class=\"login-footer\">Already a member? <a class=\"login-link\" href=\"<< loginSignupProtocol >><< host >>\/account\/register?sourcea=emailPrompt\">Login &raquo;</a></p>";
Ibles.mobileSignupPromptTemplate += "           </div>";
Ibles.mobileSignupPromptTemplate += "       </div>";
Ibles.mobileSignupPromptTemplate += "   </div>";
Ibles.mobileSignupPromptTemplate += "</div>";


Ibles.views.CallToActionView = Backbone.View.extend({
    events: {
        "click .submit-form":"submitForm",
        "click .close": "close",
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
    submitForm: function(){
    },
    setClosedCookie:function(){

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
        loginSignupProtocol:"http://",
        host: window.location.host
    }
});

Ibles.views.SignupPromptView = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.signupBannerTemplate),
    initialize: function(){
        if (this.model.get('display') === 'mobile modal'){
            //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
            this.template = _.template(Ibles.mobileTemplate)
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
                url: "/newsletter/newslettersignup?email="+encodeURIComponent(email),
                method: "GET",
                success: function() {
                    window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&bannerType="+bannerType+"&email="+encodeURIComponent(email)+"&utm_medium=cta&tum_source=popup&utm_campaign=signup";
;
                }
            });
        } else {
            window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&bannerType="+ bannerType+"&utm_medium=cta&tum_source=popup&utm_campaign=signup";
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


Ibles.views.PremiumPrompt = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.premiumPromptTemplate),
    initialize: function(options){
    if (this.model.get('display') === 'mobile modal'){
        //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
        this.template = _.template(Ibles.mobilePremiumPromptTemplate)
    }
       this.render();
    },
    setClosedCookie: function(){
        // show prompt once day
        $.cookie('PremiumPromptClosedBefore', 'true', {path: '/', expires: 1});
    }
});

Ibles.views.FooterPrompt = Ibles.views.CallToActionView.extend({
    template: _.template(Ibles.footerPromptTemplate),
    initialize: function(options){
        this.render();
    },
	close: function(){
        this.$('.call-to-action-footer').fadeOut(200);
		this.setClosedCookie();
	},
    setClosedCookie: function(){
        // show banner once day
        $.cookie('FooterPromptClosedBefore', 'true', {path: '/', expires: 1});
    }
});

Ibles.views.SignupEmailPrompt = Ibles.views.CallToActionView.extend({
    events: {
        "click .submit-btn":"submitForm",
        "click .close": "close"
    },

    template: _.template(Ibles.signupPromptTemplate),

    initialize: function(){
        if (this.model.get('display') === 'mobile modal'){
            //Mobile modals have different templates b/c of Bootstrap 2 vs 3 structures. TODO: fix when transitioned to BS3
            this.template = _.template(Ibles.mobileSignupPromptTemplate)
        }
        this.render();
    },
    submitForm: function(e){
        e.preventDefault();
        var that = this;
        var email = this.$el.find('.email-field').val() || "",
            sourceaUrl = encodeURIComponent(window.location.pathname + window.location.search),
            protocol = this.model.get('loginSignupProtocol');
        if (email) {
            $.ajax({
                url: "/newsletter/newslettersignup?email="+encodeURIComponent(email),
                method: "GET",
                success: function() {
                    window.location = protocol + window.location.host + "/account/register?sourcea=prompt&sourceaUrl="+sourceaUrl+"&email="+encodeURIComponent(email)+"&utm_medium=cta&tum_source=popup&utm_campaign=signup";
                    ;
                }
            });
        } else {
            window.location = protocol + window.location.host + "/account/register?sourcea=banner&sourceaUrl="+sourceaUrl+"&utm_medium=cta&tum_source=popup&utm_campaign=signup";
        }
    },
    show: function(){
        this.$('.auth-prompt').modal('show');
    },
    close: function(){
        this.$('.auth-prompt').modal('hide');
        this.setClosedCookie();

    },
    setClosedCookie: function(){
        // show prompt once day
        $.cookie('SignupPromptClosedBefore', 'true', {path: '/', expires: 1});
    }
});

Ibles.showSignupPrompt = function(model, delay) {
    var signup_model = new Ibles.models.CallToAction(model);
    var signup_prompt = new Ibles.views.SignupPromptView({model:signup_model});
    $("body").append(signup_prompt.$el);
    setTimeout(function(){
        signup_prompt.show();
    }, delay);
};

Ibles.showPremiumPrompt = function(model, delay) {
    var premium_model = new Ibles.models.CallToAction(model);

    var view = new Ibles.views.PremiumPrompt({model:premium_model});
    $("body").append(view.$el);

    setTimeout(function(){
        view.show();
    }, delay);
};

Ibles.showFooterBarPrompt = function(model, delay) {
    var footer_cta_model = new Ibles.models.CallToAction(model);
    var footer_prompt = new Ibles.views.FooterPrompt({model: footer_cta_model});
    $("body").append(footer_prompt.$el);
    setTimeout(function(){
        footer_prompt.show();
    }, delay);
};

Ibles.showSignupEmailPrompt = function(model, delay){
    var signup_email_model = new Ibles.models.CallToAction(model);
    var signup_email_prompt = new Ibles.views.SignupEmailPrompt({model: signup_email_model});
    $("body").append(signup_email_prompt.$el);
    setTimeout(function(){
        signup_email_prompt.show();
    }, delay);
};