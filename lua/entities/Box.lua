local Box = {}

function Box.new(pos)
    local self = {}
    self.Renderable = {
        zValue = 0
    }
    self.Graphical = {
        texture = "wood.png",
        textureRect = {0, 0, 4, 4 },
        position = {-1.9, -1.9}
    }
    self.Spatial = {
        position = pos
    }
    self.Physical = {
        b2BodyDef = {
            position = pos,
            type = "b2_dynamicBody"
        },

        b2FixtureDef = {
            density = 1.0,
            friction = .3,
            restitution = .2,
            b2PolygonShape = {
                    setAsBox = {1.0, 1.0}
            }
        }
    }
    return self
end

return Box