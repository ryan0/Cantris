--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/25/2016
-- Time: 11:21 PM
-- To change this template use File | Settings | File Templates.
--

local StaticPolygon = {}

function StaticPolygon.new(coords)
    local self = {}
    self.Spatial = {
        position = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = {0, 0},
            type = "b2_staticBody"
        },
        b2FixtureDef = {
            friction = .8,
            restitution = 0.0,
            b2PolygonShape = {
                vertices = coords
            }
        }
    }
    return self
end

return StaticPolygon

