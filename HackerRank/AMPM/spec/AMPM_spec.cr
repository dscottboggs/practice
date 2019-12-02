require "spec"
require "../AMPM"

describe "to24time" do
  it "outputs the right time when given AM" do
    twelve_hour = TimeRepr.new "10:43 AM"
    twelve_hour.to24time.should eq "10:43"
    twelve_hour = TimeRepr.new "2:02 AM"
    twelve_hour.to24time.should eq "2:02"
  end
  it "outputs the right time when given PM" do
    TimeRepr.new("10:43 PM").to24time.should eq "22:43"
    TimeRepr.new("2:02 PM").to24time.should eq "14:02"
  end
  it "fails when given an invalid hour" do
    expect_raises Exception, "Invalid hour 13" do
      TimeRepr.new("13:15 AM")
    end
    expect_raises ArgumentError do
      TimeRepr.new "-4:08 PM"
    end
  end
end

