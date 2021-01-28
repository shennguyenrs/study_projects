// Validation Phone Number
const validatePhone = (number) => {
  const pattern = new RegExp(/([0-9]{3})-([0-9]{3})-([0-9]{4})$/);

  if (pattern.test(number)) {
    return true;
  }

  return false;
};

export default validatePhone;
