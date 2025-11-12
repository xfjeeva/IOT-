function Test1()
{
    Browsers.Item(btChrome).Navigate("https://auth.geeksforgeeks.org/");
    let browser = Aliases.browser;
    browser.BrowserWindow.Maximize();
    let form = browser.pageLoginGeeksforgeeks.sectionConent1.formLogin;
    let textbox = form.textboxLuser;
    textbox.Click();
    //enter your email
    textbox.Keys("enter your email");
    let passwordBox = form.passwordboxPassword;
    passwordBox.Click();
    passwordBox.SetText(Project.Variables.Password2);
    let button = form.buttonSignIn;
    button.ClickButton();
    passwordBox.Click();
    passwordBox.SetText(Project.Variables.Password2);
    button.ClickButton();
    let page = browser.pageRoadblockV2;
    page.Wait();
    page.panelLowerSectionText.Click();
}
