
// Hàm validator <=> Đối tượng

function Validator(options) {

    var selectorRules = {};


// Hàm thực hiện validate
    function validate(inputElement, rule) {
        var errorElement = inputElement.parenElement.querySelector('options.errorSelector');
        // var  errorMessage = rule.test(inputElement.value);
        var errorMessage;

        // Lấy ra các rules cảu selector
        var rules = selectorRules[rule.selector];

        // Lặp qua từng rule và kiểm tra
        // Nếu có lỗi thì dừng việc kiểm tra
        for (let index = 0; index < rule.length; index++) {
           errorMessage = rule[index](inputElement.value);
            if (errorMessage) break;
        }

        if (errorMessage) {
            errorElement.innerText = errorMessage;
            inputElement.parenElement.classList.add('invalid');
        } else {
            errorElement.innerText = '';
            inputElement.parenElement.classList.remove('invalid');
        }

        return !errorMessage;
    }
// Lấy element của form cần validate
    var formElement = document.querySelector(options.form); 
    if (formElement){

        // Lặp qua mỗi rule và xử lý (lắng nghe sự kiện blur, input, ...)

        formElement.onsubmit = function(e) {
            e.preventDefault();

            var isFormVlaid = true;

            // Lặp qua từng rules và validate
            options.rules.forEach(function(rule) {
                var inputElement = formElement.querySelector(rule.selector);
                var isValid = validate(inputElement, rule);
                if (!isValid){
                    isFormVlaid = false;
                }
            });   

            


            if (isFormVlaid) {
                // Trường hợp submit với hành vi JavaScript
                if (typeof options.onSubmit === 'function'){
                    
                    var enableInputs = formElement.querySelectorAll('[name]');
                    var formValues = Array.from(enableInputs).reduce(function(values, input){
                        return (values[input.name] = input.value) && values;
                    }, {});
                    options.onSubmit(formValues);
                } 
                // Trường h[ submit với hành vi mặc định]
                else {
                    formElement.submit();
                }
            }      
        }

        options.rules.forEach(function(rule) {

            // Lưu lại các rules cho mỗi input
            if (Array.isArray(selectorRules[rule.selector])) {
                selectorRules[rule.selector].push(rule.test);
            } else {
                selectorRules[rule.selector] = [rule.test];
            }

            var inputElement = formElement.querySelector(rule.selector);

            if (inputElement) {
                // Xử lý trường hợp blur khỏi input
                inputElement.onblur = function () {
                    validate(inputElement, rule);
                }
                // Xử lý trường hợp mỗi khi người dùng nhập vào input
                inputElement.oninput = function() {
                    var errorElement = inputElement.parenElement.querySelector('options.errorSelector');
                    errorElement.innerText = '';
                    inputElement.parenElement.classList.remove('invalid');
                }
            }
        });


    }

}
// ĐỊnh nghĩa rules
// Nguyên tác của các rules
// 1. Khi có lỗi => trả ra message lỗi
// 2. Khi hợp lệ => Không trả ra cái gì cả (undefined)
Validator.isRequired = function(selector, message) {

    return {
        selector: selector,
        test:  function (value) {
            return value.trim() ? undefined : 'Vui lòng nhập trường này';

        }
    };

}

Validator.isEmail = function(selector, message) {
       
    return {
        selector: selector,
        test:  function (value) {
            var regex =/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
            return regex.test(value) ? undefined : 'Trường này phải là email';
        }
    };
}
Validator.minLength = function(selector, min) {
       
    return {
        selector: selector,
        test:  function (value) {
            return value.length >= min ? undefined : `Vui lòng nhập vào tối thieeurt ${min} kí tự`;
        }
    };
}
Validator.isConfirmed = function(selector, getConfirmValue, message) {
    return {
        selector: selector,
        test:  function (value) {
            return value === getConfirmValue ? undefined : message ||'Giá trị nhập vào không chính xác';
        }
    }
}