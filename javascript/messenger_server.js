const app = require('express')();
const port = 8080;

const server = app.listen(port, () => {
    console.log('Server is running on port' + port);
});

