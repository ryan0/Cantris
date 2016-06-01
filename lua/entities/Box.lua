local Box = {}

function Box.new()
    local self = {}
    self.Renderable = {
        zValue = 0
    }
    self.Graphical = {
        texture = "wood.png",
        textureRect = {0, 0, 16, 16},
        position = {-8, -8}
    }
    self.Spatial = {
        position = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = {0, 0},
            type = "b2_dynamicBody"
        },

        b2FixtureDef = {
            density = 2.0,
            friction = 1,
            restitution = .2,
            b2PolygonShape = {
                    setAsBox = {1.0, 1.0}
            }
        }
    }
    return self
end

return Box