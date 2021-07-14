import express from "express";
import cors from "cors";

import * as routes from "./controllers/routes";

const app: express.Application = express();

// Middleware
app.use(cors());
app.use(express.json());

// CRUD routes
app.get("/api/customers", routes.getAllCustomers);
app.get("/api/customers/:id", routes.getCustomerById);
app.post("/api/customers", routes.addCustomer);
app.put("/api/customers/:id", routes.addCustomer);
app.delete("/api/customers/:id", routes.deleteCustomerById);

export default app;
