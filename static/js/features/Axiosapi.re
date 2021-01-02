open Axios;
module Form = {
  let checkNew = data => postData("/Form/checkNewData", data);
  let loginForm = data => postData("/Form/loginFormData", data);
  let badgeForm = data => postData("/Form/badgeFormData", data);
  let permiss = data => postData("/Form/permissData", data);
  let record = data => postData("/Form/recordData", data);
  let badge = data => postData("/Form/badgeData", data);
};

module Login = {
  let checkUser = data => postData("/Login/checkUserData", data);
  let loginUser = data => postData("/Login/loginUserData", data);
};

module Forget = {
  let forgetUser = data => postData("/Forget/forgetUserData", data);
};

module Code = {
  let codeUser = data => postData("/Code/codeUserData", data);
};

module Resend = {
  let resendUser = data => postData("/Resend/resendUserData", data);
};

module Signup = {
  let signupUser = data => postData("/Signup/signupUserData", data);
};

module Icon = {
  let search = data => postData("/Icon/searchData", data);
  let insert = data => postData("/Icon/insertData", data);
};

module Option = {
  let add = data => postData("/Option/addData", data);
};

module Files = {
  let upload = formData =>
    postDatac(
      "/Files/uploadData",
      formData,
      makeConfig(
        ~headers=Headers.fromObj({"Content-Type": "multipart/form-data"}),
        (),
      ),
    );
  let website = data => postData("/Files/websiteData", data);
  let download = data => postData("/Files/downloadData", data);
  let transfer = data => postData("/Files/transferData", data);
  let review = data => postData("/Files/reviewData", data);
};

module Default = {
  /*let search = data =>
    postDatac("/Home/searchData", data, makeConfig(~timeout=30000, ()));*/
  let search = data => postData("/Home/searchData", data);
  let create = data => postData("/Home/createData", data);
};