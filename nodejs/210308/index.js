const express = require('express');
const app = express();
const port = process.env.PORT || 3000;
const query = require('./db/customers');

app.use(express.json());

app.get('/api/customers', query.getAllCustomer);
app.get('/api/customers/:id', query.getCustomerById);
app.post('/api/customers', query.addCustomer);
app.delete('/api/customers/:id', query.deleteCustomer);
app.put('/api/customers/:id', query.updateCustomer);

app.listen(port, () => {
  console.log('App is listening on port ' + port);
});
