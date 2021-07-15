import chai from "chai";
import chaiHttp from "chai-http";

import app from "../app";

chai.use(chaiHttp);

const expect = chai.expect;

const testCustomer = {
  firstname: "test",
  lastname: "user",
  phone: "09293002903",
  email: "newtestuser@gmail.com",
};

describe("/POST customer", () => {
  it("Add new customer", () => {
    chai
      .request(app)
      .post("/api/customers")
      .set("Content-Type", "application/json")
      .send(JSON.stringify(testCustomer))
      .then((res) => {
        expect(res.status).to.equal(200);
        expect(res.body).to.be.an("object");
        expect(res.body).have.property("firstname");
      });
  });
});

describe("/GET customer", () => {
  it("Fetch all customers", () => {
    chai
      .request(app)
      .get("/api/customers")
      .then((res) => {
        expect(res.status).to.equal(200);
        expect(res.body).to.be.an("array");
        expect(res.body.length).to.be.greaterThan(0);
      });
  });
});
