import { expect } from "chai";

import presentId from "../utils/presentId";

describe("Get present id", () => {
  it("Should return value greater than 0", async () => {
    const value = await presentId();
    expect(value > 0).to.be.true;
  });
});
